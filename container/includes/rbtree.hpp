/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:05:57 by hyson             #+#    #+#             */
/*   Updated: 2022/09/16 19:47:33 by hyson            ###   ########.fr       */
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


/* rbtree */
template <typename T, class Key, class Comp, class Allocator>
class __rbtree {
 public:
  typedef T value_type;
  typedef Key key_type;
  typedef Comp compare_type;

  typedef __tree_node<value_type> node_type;
  typedef __tree_node<value_type>* node_pointer;
  typedef __tree_iterator<value_type, node_type> iterator;
  typedef __tree_iterator<const value_type, node_type> const_iterator;

  typedef Allocator allocator_type;
  typedef typename allocator_type::template rebind<node_type>::other node_allocator;
  typedef std::allocator_traits<node_allocator> node_traits;

  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  /* constructor & destructor */
  __rbtree(const compare_type& comp, const allocator_type& alloc)
    : __comp(comp), __alloc(alloc), __size(size_type()) {
    __nil = __alloc.allocate(1);
    __alloc.construct(__nil, value_type());
    __nil->__is_black = true;
    __nil->__parent = __nil;
    __nil->__left = __nil;
    __nil->__right = __nil;
    __end = __construct_node(value_type());
    __end->__is_black = true;
    __begin = __end;
  }
  __rbtree(const __rbtree& t)
    : __comp(t.__comp), __alloc(t.__alloc), __size(size_type()) {
    __nil = __alloc.allocate(1);
    __alloc.construct(__nil, value_type());
    __nil->__is_black = true;
    __nil->__parent = __nil;
    __nil->__left = __nil;
    __nil->__right = __nil;
    __end = __construct_node(value_type());
    __end->__is_black = true;
    __begin = __end;
    insert(t.begin(), t.end());
  }
  ~__rbtree(void) {
    __destruct_node_recursive(__end);
    __destruct_node(__nil);
  }

  /* member function for util */
  __rbtree& operator=(const __rbtree& t) {
    if (this != &t) {
      __rbtree tmp(t);
      swap(tmp);
    }
    return *this;
  }

  /* iterators */
  iterator begin(void) {
    return iterator(__begin, __nil);
  }
  const_iterator begin(void) const {
    return const_iterator(__begin, __nil);
  }
  iterator end(void) {
    return iterator(__end, __nil);
  }
  const_iterator end(void) const {
    return const_iterator(__end, __nil);
  }

  /* capacity */
  size_type size(void) const {
    return __size;
  }
  size_type max_size(void) const {
    return std::min<size_type>(std::numeric_limits<size_type>::max(),
                               node_traits::max_size(node_allocator()));
  }
  bool empty(void) const {
    return __size == 0;
  }

  /* modifiers */
  //COMMENT map에서 insert를 할때 Key가 이미 존재하면 key 넣지 않음
  ft::pair<iterator, bool> insert(const value_type& value) {
    node_pointer ptr = __search_parent(value);
	//COMMENT 같은 key가 이미 존재할때
    if (ptr != __end && __is_equal(ptr->__value, value, __comp)) {
      return ft::make_pair(iterator(ptr, __nil), false);
    }
	//COMMENT key가 존재하지 않을때 key 삽입
    return ft::make_pair(iterator(__insert_internal(value, ptr), __nil), true);
  }
  iterator insert(iterator position, const value_type& value) {
    node_pointer ptr = __search_parent(value, position.base());
    if (ptr != __end && __is_equal(ptr->__value, value, __comp)) {
      return iterator(ptr, __nil);
    }
    return iterator(__insert_internal(value, ptr), __nil);
  }
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    for ( ; first != last ; first++) {
      insert(*first);
    }
  }
  iterator erase(iterator position) {
    if (__size == 0) {
      return iterator(__nil, __nil);
    }
    iterator tmp(position);
    ++tmp;
    if (position == begin()) {
      __begin = tmp.base();
    }
    --__size;
    __remove_internal(position.base());
    __destruct_node(position.base());
    return tmp;
  }
  template <typename U>
  size_type erase(const U& value) {
    iterator i(__find_internal(value), __nil);
    if (i == end()) {
      return 0;
    }
    if (i == begin()) {
      iterator tmp(i);
      ++tmp;
      __begin = tmp.base();
    }
    --__size;
    __remove_internal(i.base());
    __destruct_node(i.base());
    return 1;
  }
  void erase(iterator first, iterator last) {
    for ( ; first != last ; ) {
      first = erase(first);
    }
  }
  void swap(__rbtree& t) {
    std::swap(__nil, t.__nil);
    std::swap(__begin, t.__begin);
    std::swap(__end, t.__end);
    std::swap(__comp, t.__comp);
    std::swap(__alloc, t.__alloc);
    std::swap(__size, t.__size);
  }
  void clear(void) {
    __rbtree tmp(__comp, __alloc);
    swap(tmp);
  }

  /* lookup operations */
  iterator find(const key_type& key) {
    return iterator(__find_internal(key), __nil);
  }
  const_iterator find(const key_type& key) const {
    return const_iterator(__find_internal(key), __nil);
  }
  iterator lower_bound(const key_type& key) {
    return iterator(__lower_bound_internal(key), __nil);
  }
  //TODO lower_bound / upper_bound 다시 찾아보기
  const_iterator lower_bound(const key_type& key) const {
    return const_iterator(__lower_bound_internal(key), __nil);
  }
  //COMMENT 초과
  iterator upper_bound(const key_type& key) {
    return iterator(__upper_bound_internal(key), __nil);
  }
  const_iterator upper_bound(const key_type& key) const {
    return const_iterator(__upper_bound_internal(key), __nil);
  }
  ft::pair<iterator, iterator> equal_range(const key_type& key) {
    return __equal_range_internal(key);
  }
  ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
    return __equal_range_internal(key);
  }

  /* allocator */
  allocator_type get_allocator(void) const {
    return __alloc;
  }

 private:
  node_pointer __nil;
  node_pointer __begin;
  node_pointer __end;
  compare_type __comp;
  node_allocator __alloc;
  size_type __size;

  /* root */
  //COMMENT end의 왼쪽 자식이 루트다
  node_pointer __get_root(void) const {
    return __end->__left;
  }
  void __set_root(const node_pointer ptr) {
    ptr->__parent = __end;
    __end->__left = ptr;
  }

  /* modifiers */
  //COMMENT 노드 생성 후 주소 반환
  node_pointer __construct_node(const value_type& value) {
    node_pointer ptr = __alloc.allocate(1);
    __alloc.construct(ptr, value);
    ptr->__parent = __nil;
    ptr->__left = __nil;
    ptr->__right = __nil;
    ptr->__is_black = false;
    return ptr;
  }
  void __destruct_node(node_pointer ptr) {
    __alloc.destroy(ptr);
    __alloc.deallocate(ptr, 1);
  }
  //COMMENT 재귀 돌리면서 노드 왼쪽 오른쪽 방문하면서 삭제
  void __destruct_node_recursive(node_pointer ptr) {
    if (ptr == __nil) {
      return;
    }
    __destruct_node_recursive(ptr->__left);
    __destruct_node_recursive(ptr->__right);
    __destruct_node(ptr);
  }
  //COMMENT 부모가 될 노드 찾기
  //position을 넣어주면 그 position이 유효한지 확인하고 더 빨리 넣어주고,
  //유효한 위치가 아니면 부모에서부터 찾음
  node_pointer __search_parent(const value_type& value, node_pointer position = ft::nil) {
    if (position && position != __end) {
      if (__comp(value, position->__value) && position->__left == __nil) {
        iterator prev = iterator(position, __nil);
        if (prev == begin() || __comp(*--prev, value)) {
          return position;
        }
      } else if (position->__right == __nil) {
        iterator next = iterator(position, __nil);
        if (next == end() || __comp(value, *++next)) {
          return position;
        }
      }
    }
	//COMMENT position이 유효하지 않을때 상황
    node_pointer cur = __get_root();
    node_pointer tmp = __end;
    for ( ; cur != __nil ; ) {
      tmp = cur;
      if (__comp(value, cur->__value)) {
        cur = cur->__left;
      } else if (__comp(cur->__value, value)) {
        cur = cur->__right;
      } else {
        return cur;
      }
    }
    return tmp;
  }
  node_pointer __insert_internal(const value_type& value, node_pointer parent) {
    node_pointer ptr = __construct_node(value);
    if (parent == __end) {
      __set_root(ptr);
    } else if (__comp(value, parent->__value)) {
      parent->__left = ptr;
    } else {
      parent->__right = ptr;
    }
    ptr->__parent = parent;
    __insert_fixup(ptr);
    __insert_update(ptr);
    return ptr;
  }
  void __insert_fixup(node_pointer ptr) {
    while (__is_red_color(ptr->__parent)) {
      if (__is_left_child(ptr->__parent)) {
        __insert_fixup_left(ptr);
      } else {
        __insert_fixup_right(ptr);
      }
    }
    __get_root()->__is_black = true;
  }
  //COMMENT 해당 부모의 노드가 왼쪽 자식일 경우
  void __insert_fixup_left(node_pointer& ptr) {
    node_pointer uncle = ptr->__parent->__parent->__right;
    if (__is_red_color(uncle)) {
      ptr->__parent->__is_black = true;
      uncle->__is_black = true;
      uncle->__parent->__is_black = false;
      ptr = uncle->__parent;
    } else {
      if (__is_right_child(ptr)) {
        ptr = ptr->__parent;
        __rotate_left(ptr);
      }
      ptr->__parent->__is_black = true;
      ptr->__parent->__parent->__is_black = false;
      __rotate_right(ptr->__parent->__parent);
    }
  }
  //COMMENT 해당 부모의 노드가 오른쪽 자식일 경우
  void __insert_fixup_right(node_pointer& ptr) {
    node_pointer uncle = ptr->__parent->__parent->__left;
    if (__is_red_color(uncle)) {
      ptr->__parent->__is_black = true;
      uncle->__is_black = true;
      uncle->__parent->__is_black = false;
      ptr = uncle->__parent;
    } else {
      if (__is_left_child(ptr)) {
        ptr = ptr->__parent;
        __rotate_right(ptr);
      }
      ptr->__parent->__is_black = true;
      ptr->__parent->__parent->__is_black = false;
      __rotate_left(ptr->__parent->__parent);
    }
  }
  void __insert_update(const node_pointer ptr) {
    if (__begin == __end || __comp(ptr->__value, __begin->__value)) {
      __begin = ptr;
    }
    __size++;
  }
  void __remove_internal(node_pointer ptr) {
    node_pointer recolor_node;
    node_pointer fixup_node = ptr;
    bool original_color = __is_black_color(ptr);
    if (ptr->__left == __nil) {
      recolor_node = ptr->__right;
      __transplant(ptr, ptr->__right);
    } else if (ptr->__right == __nil) {
      recolor_node = ptr->__left;
      __transplant(ptr, ptr->__left);
    } else {
      fixup_node = __get_min_node(ptr->__right, __nil);
      original_color = __is_black_color(fixup_node);
      recolor_node = fixup_node->__right;
      if (fixup_node->__parent == ptr) {
        recolor_node->__parent = fixup_node;
      } else {
        __transplant(fixup_node, fixup_node->__right);
        fixup_node->__right = ptr->__right;
        fixup_node->__right->__parent = fixup_node;
      }
      __transplant(ptr, fixup_node);
      fixup_node->__left = ptr->__left;
      fixup_node->__left->__parent = fixup_node;
      fixup_node->__is_black = __is_black_color(ptr);
    }
    if (original_color) {
      __remove_fixup(recolor_node);
    }
  }
  void __remove_fixup(node_pointer ptr) {
    while (ptr != __get_root() && __is_black_color(ptr)) {
      if (__is_left_child(ptr)) {
        __remove_fixup_left(ptr);
      } else {
        __remove_fixup_right(ptr);
      }
    }
    ptr->__is_black = true;
  }
  void __remove_fixup_left(node_pointer& ptr) {
    node_pointer sibling = ptr->__parent->__right;
    if (__is_red_color(sibling)) {
      sibling->__is_black = true;
      ptr->__parent->__is_black = false;
      __rotate_left(ptr->__parent);
      sibling = ptr->__parent->__right;
    }
    if (__is_black_color(sibling->__left) && __is_black_color(sibling->__right)) {
      sibling->__is_black = false;
      ptr = ptr->__parent;
    } else if (__is_black_color(sibling->__right)) {
      sibling->__left->__is_black = true;
      sibling->__is_black = false;
      __rotate_right(sibling);
      sibling = ptr->__parent->__right;
    }
    if (__is_red_color(sibling->__right)) {
      sibling->__is_black = __is_black_color(ptr->__parent);
      ptr->__parent->__is_black = true;
      sibling->__right->__is_black = true;
      __rotate_left(ptr->__parent);
      ptr = __get_root();
    }
  }
  void __remove_fixup_right(node_pointer& ptr) {
    node_pointer sibling = ptr->__parent->__left;
    if (__is_red_color(sibling)) {
      sibling->__is_black = true;
      ptr->__parent->__is_black = false;
      __rotate_right(ptr->__parent);
      sibling = ptr->__parent->__left;
    }
    if (__is_black_color(sibling->__right) && __is_black_color(sibling->__left)) {
      sibling->__is_black = false;
      ptr = ptr->__parent;
    } else if (__is_black_color(sibling->__left)) {
      sibling->__right->__is_black = true;
      sibling->__is_black = false;
      __rotate_left(sibling);
      sibling = ptr->__parent->__left;
    }
    if (__is_red_color(sibling->__left)) {
      sibling->__is_black = __is_black_color(ptr->__parent);
      ptr->__parent->__is_black = true;
      sibling->__left->__is_black = true;
      __rotate_right(ptr->__parent);
      ptr = __get_root();
    }
  }
  void __transplant(node_pointer former, node_pointer latter) {
    if (former->__parent == __end) {
      __set_root(latter);
    } else if (__is_left_child(former)) {
      former->__parent->__left = latter;
    } else {
      former->__parent->__right = latter;
    }
    latter->__parent = former->__parent;
  }
  void __rotate_left(node_pointer ptr) {
    node_pointer child = ptr->__right;
    ptr->__right = child->__left;
    if (ptr->__right != __nil) {
      ptr->__right->__parent = ptr;
    }
    node_pointer parent = ptr->__parent;
    child->__parent = parent;
    if (parent == __end) {
      __set_root(child);
    } else if (__is_left_child(ptr)) {
      parent->__left = child;
    } else {
      parent->__right = child;
    }
    child->__left = ptr;
    ptr->__parent = child;
  }
  void __rotate_right(node_pointer ptr) {
    node_pointer child = ptr->__left;
    ptr->__left = child->__right;
    if (ptr->__left != __nil) {
      ptr->__left->__parent = ptr;
    }
    node_pointer parent = ptr->__parent;
    child->__parent = parent;
    if (parent == __end) {
      __set_root(child);
    } else if (__is_left_child(ptr)) {
      parent->__left = child;
    } else {
      parent->__right = child;
    }
    child->__right = ptr;
    ptr->__parent = child;
  }

  /* lookup operations */
  template <typename U>
  node_pointer __find_internal(const U& value) const {
    node_pointer ptr = __get_root();
    while (ptr != __nil) {
      if (__comp(value, ptr->__value)) {
        ptr = ptr->__left;
      } else if (__comp(ptr->__value, value)) {
        ptr = ptr->__right;
      } else {
        return ptr;
      }
    }
    return __end;
  }
  node_pointer __lower_bound_internal(const key_type& key) const {
    node_pointer ptr = __get_root();
    node_pointer tmp = __end;
    while (ptr != __nil) {
      if (!__comp(ptr->__value, key)) {
        tmp = ptr;
        ptr = ptr->__left;
      } else {
        ptr = ptr->__right;
      }
    }
    return tmp;
  }
  node_pointer __upper_bound_internal(const key_type& key) const {
    node_pointer ptr = __get_root();
    node_pointer tmp = __end;
    while (ptr != __nil) {
      if (__comp(key, ptr->__value)) {
        tmp = ptr;
        ptr = ptr->__left;
      } else {
        ptr = ptr->__right;
      }
    }
    return tmp;
  }
  template <typename U>
  ft::pair<iterator, iterator> __equal_range_internal(const U& value) {
    node_pointer ptr = __get_root();
    node_pointer tmp = __end;
    while (ptr != __nil) {
      if (__comp(value, ptr->__value)) {
        tmp = ptr;
        ptr = ptr->__left;
      } else if (__comp(ptr->__value, value)) {
        ptr = ptr->__right;
      } else {
        if (ptr->__right != __nil) {
          tmp = __get_min_node(ptr->__right, __nil);
        }
        return ft::make_pair(iterator(ptr, __nil), iterator(tmp, __nil));
      }
    }
    return ft::make_pair(iterator(tmp, __nil), iterator(tmp, __nil));
  }
  template <typename U>
  ft::pair<const_iterator, const_iterator> __equal_range_internal(const U& value) const {
    node_pointer ptr = __get_root();
    node_pointer tmp = __end;
    while (ptr != __nil) {
      if (__comp(value, ptr->__value)) {
        tmp = ptr;
        ptr = ptr->__left;
      } else if (__comp(ptr->__value, value)) {
        ptr = ptr->__right;
      } else {
        if (ptr->__right != __nil) {
          tmp = __get_min_node(ptr->__right, __nil);
        }
        return ft::make_pair(const_iterator(ptr, __nil), const_iterator(tmp, __nil));
      }
    }
    return ft::make_pair(const_iterator(tmp, __nil), const_iterator(tmp, __nil));
  }
};
}

#endif
