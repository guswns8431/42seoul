/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:06:58 by hyson             #+#    #+#             */
/*   Updated: 2022/09/17 13:35:58 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

//COMMENT less, binary_function
# include <functional>
//COMMENT allocator
# include <memory>
# include "./algorithm.hpp"
# include "./pair.hpp"
# include "./random_access_iterator.hpp"
# include "./rbtree.hpp"
# include "./reverse_iterator.hpp"

namespace ft
{

/*--------------------------------------------------------------------------*/
/*									M A P									*/
/*--------------------------------------------------------------------------*/
	//COMMENT map은 각 노드가 key와 value 쌍으로 이루어진 트리. 중복을 허용하지 않습니다.
	//디폴트로 오름차순으로 정렬
	//std::less 첫번째 인자가 두번째 인자보다 작으면 true 반환 (bool)
	//FIXED typename U에서 Key로 변경
	template <typename Key, typename V, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, V> > >
	class map
	{
		public:
			//COMMENT Key
			typedef Key key_type;
			//COMMENT Value
			typedef V mapped_type;
			typedef ft::pair<const Key, V> value_type;
			typedef Compare key_compare;

			typedef Allocator allocator_type;
			typedef typename allocator_type::template rebind<value_type>::other type_allocator;
			//COMMENT allocator의 특성을 파악하기 위해 allocator_traits안에 allocator 넣어서 확인
			typedef std::allocator_traits<type_allocator> type_traits;
			typedef typename type_traits::pointer pointer;
			typedef typename type_traits::const_pointer const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;

			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;

/*------------------------------------------------------------------------------*/
/*							M E M B E R _ C L A S S								*/
/*------------------------------------------------------------------------------*/
			//COMMENT https://cplusplus.com/reference/functional/binary_function/
			//algorithm에 필요한 typedef를 편하게 하기 위해 이용하는 클래스라고 생각하면됨
			//https://stackoverflow.com/questions/4203690/what-do-we-need-unary-function-and-binary-function-for
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;

				public:
					value_compare(key_compare c) : comp(c) {}
					~value_compare(void) {}

					bool operator()(const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
					bool operator()(const value_type& x, const key_type& y) const
					{
						return (comp(x.first, y));
					}
					bool operator()(const key_type& x, const value_type& y) const
					{
						return (comp(x, y.first));
					}
			};

			typedef typename ft::__rbtree<value_type, key_type, value_compare, allocator_type>::iterator iterator;
	 		typedef typename ft::__rbtree<value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


  /* constructor & destructor */
  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type())
    : __key_comp(comp), __value_comp(comp), __tree(__value_comp, alloc) {}
  template <class InputIterator>
  map(InputIterator first,
      InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type(),
      typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
    : __key_comp(comp), __value_comp(comp), __tree(__value_comp, alloc) {
    insert(first, last);
  }
  map(const map& m)
    : __key_comp(m.__key_comp),
      __value_comp(m.__value_comp),
      __tree(m.__tree) {}
  ~map(void) {}

  /* member function for util */
  map& operator=(const map& m) {
    if (this != &m) {
      __key_comp = m.__key_comp;
      __value_comp = m.__value_comp;
      __tree = m.__tree;
    }
    return *this;
  }

  /* iterators */
  iterator begin(void) {
    return __tree.begin();
  }
  const_iterator begin(void) const {
    return __tree.begin();
  }
  iterator end(void) {
    return __tree.end();
  }
  const_iterator end(void) const {
    return __tree.end();
  }
  reverse_iterator rbegin(void) {
    return reverse_iterator(end());
  }
  const_reverse_iterator rbegin(void) const {
    return reverse_iterator(end());
  }
  reverse_iterator rend(void) {
    return reverse_iterator(begin());
  }
  const_reverse_iterator rend(void) const {
    return reverse_iterator(begin());
  }

  /* capacity */
  bool empty(void) const {
    return __tree.empty();
  }
  size_type size(void) const {
    return __tree.size();
  }
  size_type max_size(void) const {
    return __tree.max_size();
  }

  /* element access */
  mapped_type& operator[](const key_type& key) {
    ft::pair<iterator, bool> p = insert(ft::make_pair(key, mapped_type()));
    return p.first->second;
  }
  mapped_type& at(const key_type& key) {
    iterator i = find(key);
    if (i == end()) {
      throw std::out_of_range("index out of range");
    }
    return i->second;
  }
  const mapped_type& at(const key_type& key) const {
    const_iterator i = find(key);
    if (i == end()) {
      throw std::out_of_range("index out of range");
    }
    return i->second;
  }

  /* modifiers */
  ft::pair<iterator, bool> insert(const value_type& value) {
    return __tree.insert(value);
  }
  iterator insert(iterator position, const value_type& value) {
    return __tree.insert(position, value);
  }
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    __tree.insert(first, last);
  }
  void erase(iterator position) {
    __tree.erase(position);
  }
  size_type erase(const key_type& key) {
    return __tree.erase(key);
  }
  void erase(iterator first, iterator last) {
    __tree.erase(first, last);
  }
  void swap(map& m) {
    __tree.swap(m.__tree);
  }
  void clear(void) {
    __tree.clear();
  }

  /* observers */
  key_compare key_comp(void) const {
    return __key_comp;
  }
  value_compare value_comp(void) const {
    return __value_comp;
  }

  /* lookup operations */
  iterator find(const key_type& key) {
    return __tree.find(key);
  }
  const_iterator find(const key_type& key) const {
    return __tree.find(key);
  }
  size_type count(const key_type& key) const {
    return !(find(key) == end());
  }
  iterator lower_bound(const key_type& key) {
    return __tree.lower_bound(key);
  }
  const_iterator lower_bound(const key_type& key) const {
    return __tree.lower_bound(key);
  }
  iterator upper_bound(const key_type& key) {
    return __tree.upper_bound(key);
  }
  const_iterator upper_bound(const key_type& key) const {
    return __tree.upper_bound(key);
  }
  ft::pair<iterator, iterator> equal_range(const key_type& key) {
    return __tree.equal_range(key);
  }
  ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
    return __tree.equal_range(key);
  }

  /* allocator */
  allocator_type get_allocator(void) const {
    return __tree.get_allocator();
  }

 private:
  key_compare __key_comp;
  value_compare __value_comp;
  ft::__rbtree<value_type, key_type, value_compare, allocator_type> __tree;
};

/* relational operators */
template <typename Key, typename V, class Compare, class Allocator>
bool operator==(const ft::map<Key, V, Compare, Allocator>& x,
                const ft::map<Key, V, Compare, Allocator>& y) {
  return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <typename Key, typename V, class Compare, class Allocator>
bool operator!=(const ft::map<Key, V, Compare, Allocator>& x,
                const ft::map<Key, V, Compare, Allocator>& y) {
  return !(x == y);
}

template <typename Key, typename V, class Compare, class Allocator>
bool operator<(const ft::map<Key, V, Compare, Allocator>& x,
               const ft::map<Key, V, Compare, Allocator>& y) {
  return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <typename Key, typename V, class Compare, class Allocator>
bool operator<=(const ft::map<Key, V, Compare, Allocator>& x,
                const ft::map<Key, V, Compare, Allocator>& y) {
  return !(y < x);
}

template <typename Key, typename V, class Compare, class Allocator>
bool operator>(const ft::map<Key, V, Compare, Allocator>& x,
               const ft::map<Key, V, Compare, Allocator>& y) {
  return y < x;
}

template <typename Key, typename V, class Compare, class Allocator>
bool operator>=(const ft::map<Key, V, Compare, Allocator>& x,
                const ft::map<Key, V, Compare, Allocator>& y) {
  return !(x < y);
}

/* non member function for util */
template <typename Key, typename V, class Compare, class Allocator>
void swap(ft::map<Key, V, Compare, Allocator>& x,
          ft::map<Key, V, Compare, Allocator>& y) {
  x.swap(y);
}

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_MAP_HPP_
