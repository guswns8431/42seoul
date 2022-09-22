/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:06:58 by hyson             #+#    #+#             */
/*   Updated: 2022/09/22 19:14:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
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
	template <typename Key, typename V, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, V> > >
	class map
	{
		public:
			typedef Key key_type;
			typedef V mapped_type;
			typedef ft::pair<const Key, V> value_type;
			typedef Compare key_compare;

			typedef Allocator allocator_type;
			typedef typename allocator_type::template rebind<value_type>::other type_allocator;
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

			typedef typename ft::RBTree<value_type, key_type, value_compare, allocator_type>::iterator iterator;
	 		typedef typename ft::RBTree<value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


/*--------------------------------------------------------------------------*/
/*				C O N S T R U C T O R _ & _ D E S T R U C T O R				*/
/*--------------------------------------------------------------------------*/
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : key_comp_(comp), value_comp_(comp), tree_(value_comp_, alloc) {}
			template <class InputIterator>
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
			iterator insert(iterator position, const value_type& value)
			{
				return (tree_.insert(position, value));
			}
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				tree_.insert(first, last);
			}
			void erase(iterator position)
			{
				tree_.erase(position);
			}
			size_type erase(const key_type& key)
			{
				return (tree_.erase(key));
			}
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
			size_type count(const key_type& key) const
			{
				return (!(find(key) == end()));
			}
			iterator find(const key_type& key)
			{
				return (tree_.find(key));
			}
			const_iterator find(const key_type& key) const
			{
				return (tree_.find(key));
			}
			ft::pair<iterator, iterator> equal_range(const key_type& key)
			{
				return (tree_.EqualRange(key));
			}
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
			{
				return (tree_.EqualRange(key));
			}
			iterator lower_bound(const key_type& key)
			{
				return (tree_.LowerBound(key));
			}
			const_iterator lower_bound(const key_type& key) const
			{
				return (tree_.LowerBound(key));
			}
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
