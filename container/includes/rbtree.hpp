/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:05:57 by hyson             #+#    #+#             */
/*   Updated: 2022/09/16 17:00:45 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

// #include <algorithm>
// #include <limits>
// #include <memory>
#include "./iterator_traits.hpp"
// #include "./pair.hpp"
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

}

#endif
