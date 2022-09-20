/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:06:58 by hyson             #+#    #+#             */
/*   Updated: 2022/09/20 19:50:14 by hyson            ###   ########.fr       */
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

					//COMMENT key값들을 비교
					//COMMENT pair와 pair가 들어왔을 경우
					bool operator()(const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
					//COMMENT pair와 키가 들어왔을 경우
					bool operator()(const value_type& x, const key_type& y) const
					{
						return (comp(x.first, y));
					}
					//COMMENT key와 pair가 들어왔을 경우
					bool operator()(const key_type& x, const value_type& y) const
					{
						return (comp(x, y.first));
					}
			};

			typedef typename ft::RBTree<value_type, key_type, value_compare, allocator_type>::iterator iterator;
	 		typedef typename ft::RBTree<value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


/*--------------------------------------------------------------------------*/
/*				C O N S T R U C T O R _ & _ D E S T R U C T O R				*/
/*--------------------------------------------------------------------------*/
			//COMMENT explicit 암묵적 형변환
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : key_comp_(comp), value_comp_(comp), tree_(value_comp_, alloc) {}
			template <class InputIterator>
			//COMMENT enable_if 필요한 이유 vector 생성자쪽에 주석 달았으니 궁금하면 확인.
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) : key_comp_(comp), value_comp_(comp), tree_(value_comp_, alloc)
			{
				insert(first, last);
			}
			map(const map& m) : key_comp_(m.key_comp_), value_comp_(m.value_comp_), tree_(m.tree_) {}
			~map(void) {}

/*------------------------------------------------------------------------------*/
/*							M E M B E R _ F U N C T I O N						*/
/*------------------------------------------------------------------------------*/
			map& operator=(const map& m)
			{
				if (this != &m)
				{
					key_comp_ = m.key_comp_;
					value_comp_ = m.value_comp_;
					tree_ = m.tree_;
				}
				return (*this);
			}
			allocator_type get_allocator(void) const
			{
    			return (tree_.get_allocator());
			}

/*--------------------------------------------------------------------------*/
/*						E L E M E N T _ A C C E S S							*/
/*--------------------------------------------------------------------------*/
			//COMMENT key가 있으면 map은 중복이 허용되지 않기 때문에 추가 해주지 않음.
			//key가 중복되지 않으면 key : value 셋팅해주고 value 반환
			mapped_type& operator[](const key_type& key)
			{
				ft::pair<iterator, bool> p = insert(ft::make_pair(key, mapped_type()));
				return (p.first->second);
			}
			mapped_type& at(const key_type& key)
			{
				iterator i = find(key);
				if (i == end())
				{
					throw std::out_of_range("index out of range");
				}
				return (i->second);
			}
			const mapped_type& at(const key_type& key) const
			{
				const_iterator i = find(key);
				if (i == end())
				{
					throw std::out_of_range("index out of range");
				}
				return (i->second);
			}

/*------------------------------------------------------------------------------*/
/*								I T E R A T O R S								*/
/*------------------------------------------------------------------------------*/
			iterator begin(void)
			{
				return (tree_.begin());
			}
			const_iterator begin(void) const
			{
				return (tree_.begin());
			}
			iterator end(void)
			{
				return (tree_.end());
			}
			const_iterator end(void) const
			{
				return (tree_.end());
			}
			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin(void) const
			{
				return (reverse_iterator(end()));
			}
			reverse_iterator rend(void)
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend(void) const
			{
				return (reverse_iterator(begin()));
			}

/*------------------------------------------------------------------------------*/
/*								C A P A C I T Y									*/
/*------------------------------------------------------------------------------*/
			bool empty(void) const
			{
				return (tree_.empty());
			}
			size_type size(void) const
			{
				return (tree_.size());
			}
			size_type max_size(void) const
			{
				return (tree_.max_size());
			}

/*--------------------------------------------------------------------------*/
/*								M O D I F I E R	S							*/
/*--------------------------------------------------------------------------*/
			ft::pair<iterator, bool> insert(const value_type& value)
			{
				return (tree_.insert(value));
			}
			//COMMENT position 위치를 확인하고 그 위치가 유효하면, 그 자리에 삽입
			iterator insert(iterator position, const value_type& value)
			{
				return (tree_.insert(position, value));
			}
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				tree_.insert(first, last);
			}
			//COMMENT position 위치에 있는 거 삭제
			void erase(iterator position)
			{
				tree_.erase(position);
			}
			//COMMENT Key에 해당하는 요소 삭제
			size_type erase(const key_type& key)
			{
				return (tree_.erase(key));
			}
			//COMMENT first부터 last 범위 삭제
			void erase(iterator first, iterator last)
			{
				tree_.erase(first, last);
			}
			void swap(map& m)
			{
				tree_.swap(m.tree_);
			}
			void clear(void)
			{
				tree_.clear();
			}

/*--------------------------------------------------------------------------*/
/*								L O O K U P									*/
/*--------------------------------------------------------------------------*/
			//COMMENT key 찾으면 1 반환, 없으면 0
			size_type count(const key_type& key) const
			{
				return (!(find(key) == end()));
			}
			//COMMENT key 찾으면 iterator 반화느 없으면 end()반환
			iterator find(const key_type& key)
			{
				return (tree_.find(key));
			}
			const_iterator find(const key_type& key) const
			{
				return (tree_.find(key));
			}
			//COMMENT lower_bound()의 결과와 upper_bound()의 결과 반환
			ft::pair<iterator, iterator> equal_range(const key_type& key)
			{
				return (tree_.EqualRange(key));
			}
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
			{
				return (tree_.EqualRange(key));
			}
			//COMMENT key 일치 or 초과하는 것 중 가장 작은 것
			iterator lower_bound(const key_type& key)
			{
				return (tree_.LowerBound(key));
			}
			const_iterator lower_bound(const key_type& key) const
			{
				return (tree_.LowerBound(key));
			}
			//COMMENT Key보다 초과하는 것 중 가장 작은 것
			iterator upper_bound(const key_type& key)
			{
				return (tree_.UpperBound(key));
			}
			const_iterator upper_bound(const key_type& key) const
			{
				return (tree_.UpperBound(key));
			}

/*--------------------------------------------------------------------------*/
/*								O B S E R V E R S							*/
/*--------------------------------------------------------------------------*/
			key_compare key_comp(void) const
			{
				return (key_comp_);
			}
			value_compare value_comp(void) const
			{
				return (value_comp_);
			}
		private:
			key_compare key_comp_;
			value_compare value_comp_;
			ft::RBTree<value_type, key_type, value_compare, allocator_type> tree_;
};

/*--------------------------------------------------------------------------*/
/*					N O N _ M E M B E R _ F U N C T I O N S					*/
/*--------------------------------------------------------------------------*/
	template <typename Key, typename V, class Compare, class Allocator>
	bool operator==(const ft::map<Key, V, Compare, Allocator>& x, const ft::map<Key, V, Compare, Allocator>& y)
	{
		return ((x.size() == y.size()) && (ft::equal(x.begin(), x.end(), y.begin())));
	}

	template <typename Key, typename V, class Compare, class Allocator>
	bool operator!=(const ft::map<Key, V, Compare, Allocator>& x, const ft::map<Key, V, Compare, Allocator>& y)
	{
		return (!(x == y));
	}

	template <typename Key, typename V, class Compare, class Allocator>
	bool operator<(const ft::map<Key, V, Compare, Allocator>& x, const ft::map<Key, V, Compare, Allocator>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	template <typename Key, typename V, class Compare, class Allocator>
	bool operator<=(const ft::map<Key, V, Compare, Allocator>& x, const ft::map<Key, V, Compare, Allocator>& y)
	{
		return (!(y < x));
	}

	template <typename Key, typename V, class Compare, class Allocator>
	bool operator>(const ft::map<Key, V, Compare, Allocator>& x, const ft::map<Key, V, Compare, Allocator>& y)
	{
		return (y < x);
	}

	template <typename Key, typename V, class Compare, class Allocator>
	bool operator>=(const ft::map<Key, V, Compare, Allocator>& x, const ft::map<Key, V, Compare, Allocator>& y)
	{
		return (!(x < y));
	}

	template <typename Key, typename V, class Compare, class Allocator>
	void swap(ft::map<Key, V, Compare, Allocator>& x, ft::map<Key, V, Compare, Allocator>& y)
	{
		x.swap(y);
	}
}

#endif
