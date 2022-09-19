/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:05:57 by hyson             #+#    #+#             */
/*   Updated: 2022/09/19 23:00:04 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <algorithm>
#include <limits>
#include <memory>
#include "./iterator_traits.hpp"
#include "./pair.hpp"
#include "./type_traits.hpp"

namespace ft
{

/*--------------------------------------------------------------------------*/
/*								T R E E _ N O D E							*/
/*--------------------------------------------------------------------------*/
	template <typename T>
	struct TreeNode
	{
		typedef T value_type;
		typedef bool binary_type;

		TreeNode* parent_;
		TreeNode* left_;
		TreeNode* right_;
		value_type 	value_;
		//TODO is_black이 뭔지
		binary_type is_black_;

/*--------------------------------------------------------------------------*/
/*				C O N S T R U C T O R _ & _ D E S T R U C T O R				*/
/*--------------------------------------------------------------------------*/
		//TODO ft::nil 확인
		//COMMENT jseo의 코드는 tree가 nil을 가리킴으로써, parent->left->left 이런식으로 접근을할때 segfault가 터지는 것을 방지해줌
		//예를들어, 모든경우에 대해서  if(parent->left != NULL), if(parent->left->left != NULL) 이런식으로 일일이 모든 경우를 비교하는게 힘들 수 있기 때문에
		//nil객체를 가리키게함
		//한 트리당 하나의 nil 객체를 만들게 되고 모든 nil을 표현하길 원하는 곳은 그 객체를 가리킴
		TreeNode(void) : parent_(ft::nil), left_(ft::nil), right_(ft::nil), value_(value_type()), is_black_(binary_type()) {}
		TreeNode(const value_type& value) : parent_(ft::nil), left_(ft::nil), right_(ft::nil), value_(value), is_black_(binary_type()) {}
		TreeNode(const TreeNode& n) : parent_(n.parent_), left_(n.left_), right_(n.right_), value_(n.value_), is_black_(n.is_black_) {}
		~TreeNode(void) {}

/*--------------------------------------------------------------------------*/
/*						M E M B E R _ F U N C T I O N						*/
/*--------------------------------------------------------------------------*/
		TreeNode& operator=(const TreeNode& n)
		{
			if (this != &n)
			{
				parent_ = n.parent_;
				left_ = n.left_;
				right_ = n.right_;
				value_ = n.value_;
				is_black_ = n.is_black_;
			}
			return (*this);
		}
	};

/*--------------------------------------------------------------------------*/
/*					N O N _ M E M B E R _ F U N C T I O N					*/
/*--------------------------------------------------------------------------*/
	template <class NodePtr>
	bool is_left_child(const NodePtr& ptr)
	{
		return (ptr == ptr->parent_->left_);
	}

	template <class NodePtr>
	bool is_right_child(const NodePtr& ptr)
	{
		return (ptr == ptr->parent_->right_);
	}

	template <class NodePtr>
	bool is_black_color(const NodePtr& ptr)
	{
		return (ptr->is_black_);
	}

	template <class NodePtr>
	bool is_red_color(const NodePtr& ptr)
	{
		return (!ptr->is_black_);
	}

	//COMMENT 부모 노드를 기준으로 왼쪽이 작은 값이기 때문에,
	//가장 왼쪽 노드를 찾아가면 그것이 최소값
	template <class NodePtr>
	NodePtr get_min_node(NodePtr ptr, NodePtr nil)
	{
		while (ptr->left_ != nil)
		{
			ptr = ptr->left_;
		}
		return (ptr);
	}

	//COMMENT 부모 노드를 기준으로 오른쪽이 큰 값이기 때문에,
	//가장 오른쪽 노드를 찾아가면 그것이 최대값
	template <class NodePtr>
	NodePtr get_max_node(NodePtr ptr, NodePtr nil)
	{
		while (ptr->right_ != nil)
		{
			ptr = ptr->right_;
		}
		return (ptr);
	}

	//COMMENT BST의 다음 노드로 가는 법
	//다음 노드는 다음으로 큰 수를 가리킴
	template <class NodePtr>
	NodePtr get_next_node(NodePtr ptr, NodePtr nil)
	{
		//COMMENT BST에서 오른쪽이 자기 자신보다 큰 수
		//자기의 오른쪽 자식이 비어있지 않다면 그 자식의 가장 왼쪽에 있는 녀석이 다음 요소
		if (ptr->right_ != nil)
		{
			return (get_min_node(ptr->right_, nil));
		}
		//COMMENT 자식 노드에서 찾을 수 있는 최대 노드는 부모 노드 보다 클 수 없음
		//만약 현재 오른쪽 자식 노드라면 왼쪽 자식 노드가 될때까지 올라가고,
		//그 왼쪽 자식 노드의 부모 노드가 다음 요소
		//FIXED !is_left_child에서 변경
		while (is_right_child(ptr))
		{
			ptr = ptr->parent_;
		}
		//COMMENT 이미 왼쪽 자식 노드라면 부모 노드가 다음 노드
		return (ptr->parent_);
	}

	//COMMENT BST에서 이전 노드로 가는 법
	template <class NodePtr>
	NodePtr get_prev_node(NodePtr ptr, NodePtr nil)
	{
		//COMMENT 일단 먼저 왼쪽 자식 노드가 있는지 확인을 함
		//자식 노드의 가장 오른쪽 노드가 이전 노드
		if (ptr->left_ != nil)
		{
			return get_max_node(ptr->left_, nil);
		}
		//FIXED !is_right_child에서 변경
		while (is_left_child(ptr))
		{
			ptr = ptr->parent_;
		}
		return (ptr->parent_);
	}

	//COMMENT comp에 뭐가 들어올지 모르겠지만, comp를 기준으로 두 개가 같은지를 확인해줌
	template <typename U, typename V, class Comp>
	bool is_equal(const U& u, const V& v, Comp comp)
	{
		return (!comp(u, v) && !comp(v, u));
	}

/*------------------------------------------------------------------------------*/
/*							T R E E _ I T E R A T O R							*/
/*------------------------------------------------------------------------------*/
	//COMMENT map에서도 iterator가 필요. map에서는 rbtree.hpp에 구현된 iterator를 가져와서 사용
	//tree_iterator를 구현할때 참고한 reference가 있는건가?
	template <typename U, typename V>
	class TreeIterator
	{
		public:
			typedef U value_type;
			typedef value_type* pointer;
			typedef value_type& reference;
			typedef V* iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type node_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer node_pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference node_reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

/*--------------------------------------------------------------------------*/
/*				C O N S T R U C T O R _ & _ D E S T R U C T O R				*/
/*--------------------------------------------------------------------------*/
			TreeIterator(void) : cur_(ft::nil), nil_(ft::nil) {}
			TreeIterator(node_pointer cur, node_pointer nil) : cur_(cur), nil_(nil) {}
			TreeIterator(const TreeIterator& i) : cur_(i.cur_), nil_(i.nil_) {}
			~TreeIterator(void) {}

/*--------------------------------------------------------------------------*/
/*						M E M B E R _ F U N C T I O N						*/
/*--------------------------------------------------------------------------*/
			TreeIterator& operator=(const TreeIterator& i)
			{
				if (this != &i)
				{
					cur_ = i.cur_;
					nil_ = i.nil_;
				}
				return (*this);
			}

/*--------------------------------------------------------------------------*/
/*						E L E M E N T _ A C C E S S							*/
/*--------------------------------------------------------------------------*/
		node_pointer base(void) const
		{
			return (cur_);
		}
		pointer operator->(void) const
		{
			return (&cur_->value_);
		}
		reference operator*(void) const { return cur_->value_; }

		//COMMENT 우리는 nil 객체를 넣어주게 되는데, tree당 모든 nil은 하나의 nil을 가리킨다 생각하면됨
		TreeIterator& operator++(void)
		{
			cur_ = ft::get_next_node(cur_, nil_);
			return (*this);
		}
		TreeIterator& operator--(void)
		{
			cur_ = ft::get_prev_node(cur_, nil_);
			return (*this);
		}
		TreeIterator operator++(int)
		{
			TreeIterator tmp(*this);
			++(*this);
			return (tmp);
		}
		TreeIterator operator--(int)
		{
			TreeIterator tmp(*this);
			--(*this);
			return (tmp);
		}

		template <typename T>
		bool operator==(const TreeIterator<T, node_type>& i) const
		{
			return (cur_ == i.base());
		}
		template <typename T>
		bool operator!=(const TreeIterator<T, node_type>& i) const
		{
			return (!(*this == i));
		}

		//COMMENT node_type의 경우 iterator_traits를 받아서 const 처리가 되는데,
		//value_type은 특수화라서 const 오버로딩을 따로 해줘야함
		operator TreeIterator<const value_type, node_type>(void) const
		{
			return (TreeIterator<const value_type, node_type>(cur_, nil_));
		}

		//COMMENT non member function으로 구현
		//it1 == it2 와 it2 == it1 둘다 비교가능하게 하려고 구현
		//밖으로 빼도 되지만 밑 부분은 rbtree구현해야돼서 복잡할까봐 안에다가 구현
		friend bool operator==(const TreeIterator& x, const TreeIterator& y)
		{
			return (x.cur_ == y.cur_);
		}
		friend bool operator!=(const TreeIterator& x, const TreeIterator& y)
		{
			return (!(x == y));
		}

		private:
			node_pointer cur_;
			node_pointer nil_;
	};

/*--------------------------------------------------------------------------*/
/*								R B T R E E									*/
/*--------------------------------------------------------------------------*/
	template <typename T, class Key, class Comp, class Allocator>
	class RBTree
	{
		public:
			typedef T value_type;
			typedef Key key_type;
			typedef Comp compare_type;

			typedef TreeNode<value_type> node_type;
			typedef TreeNode<value_type>* node_pointer;
			typedef TreeIterator<value_type, node_type> iterator;
			typedef TreeIterator<const value_type, node_type> const_iterator;

			typedef Allocator allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other node_allocator;
			typedef std::allocator_traits<node_allocator> node_traits;

			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;

/*--------------------------------------------------------------------------*/
/*				C O N S T R U C T O R _ & _ D E S T R U C T O R				*/
/*--------------------------------------------------------------------------*/
			RBTree(const compare_type& comp, const allocator_type& alloc) : comp_(comp), alloc_(alloc), size_(size_type())
			{
				nil_ = alloc_.allocate(1);
				alloc_.construct(nil_, value_type());
				nil_->is_black_ = true;
				nil_->parent_ = nil_;
				nil_->left_ = nil_;
				nil_->right_ = nil_;
				end_ = ConstructNode(value_type());
				end_->is_black_ = true;
				begin_ = end_;
			}
			RBTree(const RBTree& t) : comp_(t.comp_), alloc_(t.alloc_), size_(size_type())
			{
				nil_ = alloc_.allocate(1);
				alloc_.construct(nil_, value_type());
				nil_->is_black_ = true;
				nil_->parent_ = nil_;
				nil_->left_ = nil_;
				nil_->right_ = nil_;
				end_ = ConstructNode(value_type());
				end_->is_black_ = true;
				begin_ = end_;
				insert(t.begin(), t.end());
			}
			~RBTree(void)
			{
				DestructNodeRecursive(end_);
				DestructNode(nil_);
			}

/*--------------------------------------------------------------------------*/
/*						M E M B E R _ F U N C T I O N						*/
/*--------------------------------------------------------------------------*/
			RBTree& operator=(const RBTree& t)
			{
				if (this != &t)
				{
					RBTree tmp(t);
					swap(tmp);
				}
				return (*this);
			}

/*--------------------------------------------------------------------------*/
/*								I T E R A T O R	S							*/
/*--------------------------------------------------------------------------*/
			iterator begin(void)
			{
				return (iterator(begin_, nil_));
			}
			const_iterator begin(void) const
			{
				return (const_iterator(begin_, nil_));
			}
			iterator end(void)
			{
				return (iterator(end_, nil_));
			}
			const_iterator end(void) const
			{
				return (const_iterator(end_, nil_));
			}

/*------------------------------------------------------------------------------*/
/*								C A P A C I T Y									*/
/*------------------------------------------------------------------------------*/
			size_type size(void) const
			{
				return (size_);
			}
			size_type max_size(void) const
			{
				return (std::min<size_type>(std::numeric_limits<size_type>::max(), node_traits::max_size(node_allocator())));
			}
			bool empty(void) const
			{
				return (size_ == 0);
			}

/*--------------------------------------------------------------------------*/
/*								M O D I F I E R	S							*/
/*--------------------------------------------------------------------------*/
			//COMMENT map에서 insert를 할때 Key가 이미 존재하면 key 넣지 않음
			ft::pair<iterator, bool> insert(const value_type& value)
			{
				node_pointer ptr = SearchParent(value);
				//COMMENT 같은 key가 이미 존재할때
				if (ptr != end_ && is_equal(ptr->value_, value, comp_))
				{
					return (ft::make_pair(iterator(ptr, nil_), false));
				}
				//COMMENT key가 존재하지 않을때 key 삽입
				return (ft::make_pair(iterator(InsertInternal(value, ptr), nil_), true));
			}
			iterator insert(iterator position, const value_type& value)
			{
				node_pointer ptr = SearchParent(value, position.base());
				if (ptr != end_ && is_equal(ptr->value_, value, comp_))
				{
					return (iterator(ptr, nil_));
				}
				return (iterator(InsertInternal(value, ptr), nil_));
			}
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for ( ; first != last ; first++)
				{
					insert(*first);
				}
			}
			iterator erase(iterator position)
			{
				if (size_ == 0)
				{
					return (iterator(nil_, nil_));
				}
				iterator tmp(position);
				++tmp;
				if (position == begin())
				{
					begin_ = tmp.base();
				}
				--size_;
				RemoveInternal(position.base());
				DestructNode(position.base());
				return (tmp);
			}
			template <typename U>
			size_type erase(const U& value)
			{
				iterator i(FindInternal(value), nil_);
				if (i == end())
				{
					return (0);
				}
				if (i == begin())
				{
					iterator tmp(i);
					++tmp;
					begin_ = tmp.base();
				}
				--size_;
				RemoveInternal(i.base());
				DestructNode(i.base());
				return (1);
			}
			void erase(iterator first, iterator last)
			{
				for ( ; first != last ; )
				{
					first = erase(first);
				}
			}
			void swap(RBTree& t)
			{
				std::swap(nil_, t.nil_);
				std::swap(begin_, t.begin_);
				std::swap(end_, t.end_);
				std::swap(comp_, t.comp_);
				std::swap(alloc_, t.alloc_);
				std::swap(size_, t.size_);
			}
			void clear(void)
			{
				RBTree tmp(comp_, alloc_);
				swap(tmp);
			}
			iterator find(const key_type& key)
			{
				return (iterator(FindInternal(key), nil_));
			}
			const_iterator find(const key_type& key) const
			{
				return (const_iterator(FindInternal(key), nil_));
			}
			iterator LowerBound(const key_type& key)
			{
				return (iterator(LowerBoundInternal(key), nil_));
			}
			//TODO LowerBound / UpperBound 다시 찾아보기
			const_iterator LowerBound(const key_type& key) const
			{
				return (const_iterator(LowerBoundInternal(key), nil_));
			}
			//COMMENT 초과
			iterator UpperBound(const key_type& key)
			{
				return (iterator(UpperBoundInternal(key), nil_));
			}
			const_iterator UpperBound(const key_type& key) const
			{
				return (const_iterator(UpperBoundInternal(key), nil_));
			}
			ft::pair<iterator, iterator> equal_range(const key_type& key)
			{
				return (EqualRangeInternal(key));
			}
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
			{
				return (EqualRangeInternal(key));
			}

			allocator_type get_allocator(void) const
			{
				return (alloc_);
			}

		private:
			node_pointer nil_;
			node_pointer begin_;
			node_pointer end_;
			compare_type comp_;
			node_allocator alloc_;
			size_type size_;

		//COMMENT end의 왼쪽 자식이 루트다
		node_pointer GetRoot(void) const
		{
			return (end_->left_);
		}
		void SetRoot(const node_pointer ptr)
		{
			ptr->parent_ = end_;
			end_->left_ = ptr;
		}

		//COMMENT 노드 생성 후 주소 반환
		node_pointer ConstructNode(const value_type& value)
		{
			node_pointer ptr = alloc_.allocate(1);
			alloc_.construct(ptr, value);
			ptr->parent_ = nil_;
			ptr->left_ = nil_;
			ptr->right_ = nil_;
			ptr->is_black_ = false;
			return (ptr);
		}
		void DestructNode(node_pointer ptr)
		{
			alloc_.destroy(ptr);
			alloc_.deallocate(ptr, 1);
		}
		//COMMENT 재귀 돌리면서 노드 왼쪽 오른쪽 방문하면서 삭제
		void DestructNodeRecursive(node_pointer ptr)
		{
			if (ptr == nil_)
			{
				return;
			}
			DestructNodeRecursive(ptr->left_);
			DestructNodeRecursive(ptr->right_);
			DestructNode(ptr);
		}
		//COMMENT 부모가 될 노드 찾기
		//position을 넣어주면 그 position이 유효한지 확인하고 더 빨리 넣어주고,
		//유효한 위치가 아니면 부모에서부터 찾음
		node_pointer SearchParent(const value_type& value, node_pointer position = ft::nil)
		{
			if (position && position != end_)
			{
				if (comp_(value, position->value_) && position->left_ == nil_)
				{
					iterator prev = iterator(position, nil_);
					if (prev == begin() || comp_(*--prev, value))
					{
						return (position);
					}
				}
				else if (position->right_ == nil_)
				{
					iterator next = iterator(position, nil_);
					if (next == end() || comp_(value, *++next))
					{
						return (position);
					}
				}
			}
			//COMMENT position이 유효하지 않을때 상황
			node_pointer cur = GetRoot();
			node_pointer tmp = end_;
			for ( ; cur != nil_ ; )
			{
				tmp = cur;
				if (comp_(value, cur->value_))
				{
					cur = cur->left_;
				}
				else if (comp_(cur->value_, value))
				{
					cur = cur->right_;
				}
				else
				{
					return (cur);
				}
			}
			return (tmp);
		}
		node_pointer InsertInternal(const value_type& value, node_pointer parent)
		{
			node_pointer ptr = ConstructNode(value);
			if (parent == end_)
			{
				SetRoot(ptr);
			}
			else if (comp_(value, parent->value_))
			{
				parent->left_ = ptr;
			}
			else
			{
				parent->right_ = ptr;
			}
			ptr->parent_ = parent;
			InsertFixup(ptr);
			InsertUpdate(ptr);
			return (ptr);
		}
		void InsertFixup(node_pointer ptr)
		{
			while (is_red_color(ptr->parent_))
			{
				if (is_left_child(ptr->parent_))
				{
					InsertFixupLeft(ptr);
				}
				else
				{
					InsertFixupRight(ptr);
				}
			}
			GetRoot()->is_black_ = true;
		}
		//COMMENT 해당 부모의 노드가 왼쪽 자식일 경우
		void InsertFixupLeft(node_pointer& ptr)
		{
			node_pointer uncle = ptr->parent_->parent_->right_;
			if (is_red_color(uncle))
			{
				ptr->parent_->is_black_ = true;
				uncle->is_black_ = true;
				uncle->parent_->is_black_ = false;
				ptr = uncle->parent_;
			}
			else
			{
				if (is_right_child(ptr))
				{
					ptr = ptr->parent_;
					RotateLeft(ptr);
				}
				ptr->parent_->is_black_ = true;
				ptr->parent_->parent_->is_black_ = false;
				RotateRight(ptr->parent_->parent_);
			}
		}
		//COMMENT 해당 부모의 노드가 오른쪽 자식일 경우
		void InsertFixupRight(node_pointer& ptr)
		{
			node_pointer uncle = ptr->parent_->parent_->left_;
			if (is_red_color(uncle))
			{
				ptr->parent_->is_black_ = true;
				uncle->is_black_ = true;
				uncle->parent_->is_black_ = false;
				ptr = uncle->parent_;
			}
			else
			{
				if (is_left_child(ptr))
				{
					ptr = ptr->parent_;
					RotateRight(ptr);
				}
				ptr->parent_->is_black_ = true;
				ptr->parent_->parent_->is_black_ = false;
				RotateLeft(ptr->parent_->parent_);
			}
		}
		void InsertUpdate(const node_pointer ptr)
		{
			if (begin_ == end_ || comp_(ptr->value_, begin_->value_))
			{
				begin_ = ptr;
			}
			size_++;
		}
		void RemoveInternal(node_pointer ptr)
		{
			node_pointer recolor_node;
			node_pointer fixup_node = ptr;
			bool original_color = is_black_color(ptr);
			if (ptr->left_ == nil_)
			{
				recolor_node = ptr->right_;
				Transplant(ptr, ptr->right_);
			}
			else if (ptr->right_ == nil_)
			{
				recolor_node = ptr->left_;
				Transplant(ptr, ptr->left_);
			}
			else
			{
				fixup_node = get_min_node(ptr->right_, nil_);
				original_color = is_black_color(fixup_node);
				recolor_node = fixup_node->right_;
				if (fixup_node->parent_ == ptr)
				{
					recolor_node->parent_ = fixup_node;
				}
				else
				{
					Transplant(fixup_node, fixup_node->right_);
					fixup_node->right_ = ptr->right_;
					fixup_node->right_->parent_ = fixup_node;
				}
				Transplant(ptr, fixup_node);
				fixup_node->left_ = ptr->left_;
				fixup_node->left_->parent_ = fixup_node;
				fixup_node->is_black_ = is_black_color(ptr);
			}
			if (original_color)
			{
			RemoveFixup(recolor_node);
			}
		}
		void RemoveFixup(node_pointer ptr)
		{
			while (ptr != GetRoot() && is_black_color(ptr))
			{
				if (is_left_child(ptr))
				{
					RemoveFixupLeft(ptr);
				}
				else
				{
					RemoveFixupRight(ptr);
				}
			}
			ptr->is_black_ = true;
		}
		void RemoveFixupLeft(node_pointer& ptr)
		{
			node_pointer sibling = ptr->parent_->right_;
			if (is_red_color(sibling))
			{
				sibling->is_black_ = true;
				ptr->parent_->is_black_ = false;
				RotateLeft(ptr->parent_);
				sibling = ptr->parent_->right_;
			}
			if (is_black_color(sibling->left_) && is_black_color(sibling->right_))
			{
				sibling->is_black_ = false;
				ptr = ptr->parent_;
			}
			else if (is_black_color(sibling->right_))
			{
				sibling->left_->is_black_ = true;
				sibling->is_black_ = false;
				RotateRight(sibling);
				sibling = ptr->parent_->right_;
			}
			if (is_red_color(sibling->right_))
			{
				sibling->is_black_ = is_black_color(ptr->parent_);
				ptr->parent_->is_black_ = true;
				sibling->right_->is_black_ = true;
				RotateLeft(ptr->parent_);
				ptr = GetRoot();
			}
		}
		void RemoveFixupRight(node_pointer& ptr)
		{
			node_pointer sibling = ptr->parent_->left_;
			if (is_red_color(sibling))
			{
				sibling->is_black_ = true;
				ptr->parent_->is_black_ = false;
				RotateRight(ptr->parent_);
				sibling = ptr->parent_->left_;
			}
			if (is_black_color(sibling->right_) && is_black_color(sibling->left_))
			{
				sibling->is_black_ = false;
				ptr = ptr->parent_;
			}
			else if (is_black_color(sibling->left_))
			{
				sibling->right_->is_black_ = true;
				sibling->is_black_ = false;
				RotateLeft(sibling);
				sibling = ptr->parent_->left_;
			}
			if (is_red_color(sibling->left_))
			{
				sibling->is_black_ = is_black_color(ptr->parent_);
				ptr->parent_->is_black_ = true;
				sibling->left_->is_black_ = true;
				RotateRight(ptr->parent_);
				ptr = GetRoot();
			}
		}
		//TODO 뭐하는 녀석인지 찾아보기
		void Transplant(node_pointer former, node_pointer latter)
		{
			if (former->parent_ == end_)
			{
				SetRoot(latter);
			}
			else if (is_left_child(former))
			{
				former->parent_->left_ = latter;
			}
			else
			{
				former->parent_->right_ = latter;
			}
			latter->parent_ = former->parent_;
		}
		void RotateLeft(node_pointer ptr)
		{
			node_pointer child = ptr->right_;
			ptr->right_ = child->left_;
			if (ptr->right_ != nil_)
			{
				ptr->right_->parent_ = ptr;
			}
			node_pointer parent = ptr->parent_;
			child->parent_ = parent;
			if (parent == end_)
			{
				SetRoot(child);
			}
			else if (is_left_child(ptr))
			{
				parent->left_ = child;
			}
			else
			{
				parent->right_ = child;
			}
			child->left_ = ptr;
			ptr->parent_ = child;
		}
		void RotateRight(node_pointer ptr)
		{
			node_pointer child = ptr->left_;
			ptr->left_ = child->right_;
			if (ptr->left_ != nil_)
			{
				ptr->left_->parent_ = ptr;
			}
			node_pointer parent = ptr->parent_;
			child->parent_ = parent;
			if (parent == end_)
			{
				SetRoot(child);
			}
			else if (is_left_child(ptr))
			{
				parent->left_ = child;
			}
			else
			{
				parent->right_ = child;
			}
			child->right_ = ptr;
			ptr->parent_ = child;
		}

		template <typename U>
		node_pointer FindInternal(const U& value) const
		{
			node_pointer ptr = GetRoot();
			while (ptr != nil_)
			{
				if (comp_(value, ptr->value_))
				{
					ptr = ptr->left_;
				}
				else if (comp_(ptr->value_, value))
				{
					ptr = ptr->right_;
				}
				else
				{
					return ptr;
				}
			}
			return (end_);
		}
		node_pointer LowerBoundInternal(const key_type& key) const
		{
			node_pointer ptr = GetRoot();
			node_pointer tmp = end_;
			while (ptr != nil_)
			{
				if (!comp_(ptr->value_, key))
				{
					tmp = ptr;
					ptr = ptr->left_;
				}
				else
				{
					ptr = ptr->right_;
				}
			}
			return (tmp);
		}
		node_pointer UpperBoundInternal(const key_type& key) const
		{
			node_pointer ptr = GetRoot();
			node_pointer tmp = end_;
			while (ptr != nil_)
			{
				if (comp_(key, ptr->value_))
				{
					tmp = ptr;
					ptr = ptr->left_;
				}
				else
				{
					ptr = ptr->right_;
				}
			}
			return (tmp);
		}
		template <typename U>
		ft::pair<iterator, iterator> EqualRangeInternal(const U& value)
		{
			node_pointer ptr = GetRoot();
			node_pointer tmp = end_;
			while (ptr != nil_)
			{
				if (comp_(value, ptr->value_))
				{
					tmp = ptr;
					ptr = ptr->left_;
				}
				else if (comp_(ptr->value_, value))
				{
					ptr = ptr->right_;
				}
				else
				{
					if (ptr->right_ != nil_)
					{
						tmp = get_min_node(ptr->right_, nil_);
					}
				return (ft::make_pair(iterator(ptr, nil_), iterator(tmp, nil_)));
				}
			}
			return (ft::make_pair(iterator(tmp, nil_), iterator(tmp, nil_)));
		}
		template <typename U>
		ft::pair<const_iterator, const_iterator> EqualRangeInternal(const U& value) const
		{
			node_pointer ptr = GetRoot();
			node_pointer tmp = end_;
			while (ptr != nil_)
			{
				if (comp_(value, ptr->value_))
				{
					tmp = ptr;
					ptr = ptr->left_;
				}
				else if (comp_(ptr->value_, value))
				{
					ptr = ptr->right_;
				}
				else
				{
					if (ptr->right_ != nil_)
					{
						tmp = get_min_node(ptr->right_, nil_);
					}
					return (ft::make_pair(const_iterator(ptr, nil_), const_iterator(tmp, nil_)));
				}
			}
			return (ft::make_pair(const_iterator(tmp, nil_), const_iterator(tmp, nil_)));
		}
	};
}

#endif
