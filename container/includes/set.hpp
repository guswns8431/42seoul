/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:12:30 by hyson             #+#    #+#             */
/*   Updated: 2022/09/21 14:53:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <functional>
# include <memory>
# include "./algorithm.hpp"
# include "./pair.hpp"
# include "./rbtree.hpp"
# include "./reverse_iterator.hpp"

namespace ft
{

/*------------------------------------------------------------------------------*/
/*									S E T										*/
/*------------------------------------------------------------------------------*/
	template <typename T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set
	{
		public:
			typedef T key_type;
			typedef T value_type;
			typedef Compare compare_type;
			typedef Compare key_compare;
			typedef Compare value_compare;

			typedef Allocator allocator_type;
			typedef typename allocator_type::template rebind<value_type>::other type_allocator;
			typedef std::allocator_traits<type_allocator> type_traits;
			typedef typename type_traits::pointer pointer;
			typedef typename type_traits::const_pointer const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;

			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;

			typedef typename ft::RBTree<const value_type, key_type, value_compare, allocator_type>::iterator iterator;
			typedef typename ft::RBTree<const value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

/*--------------------------------------------------------------------------*/
/*				C O N S T R U C T O R _ & _ D E S T R U C T O R				*/
/*--------------------------------------------------------------------------*/
			explicit set(const compare_type& comp = compare_type(), const allocator_type& alloc = allocator_type()) : comp_(comp), alloc_(alloc), tree_(comp, alloc) {}
			template <class InputIterator>
			set(InputIterator first, InputIterator last, const compare_type& comp = compare_type(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) : comp_(comp), alloc_(alloc), tree_(comp, alloc)
			{
				insert(first, last);
			}
			set(const set& s) : comp_(s.comp_), alloc_(s.alloc_), tree_(s.tree_) {}
			~set(void) {}

/*--------------------------------------------------------------------------*/
/*						M E M B E R _ F U N C T I O N						*/
/*--------------------------------------------------------------------------*/
			set& operator=(const set& s)
			{
				if (this != &s)
				{
					comp_ = s.comp_;
					alloc_ = s.alloc_;
					tree_ = s.tree_;
				}
				return (*this);
			}

			allocator_type get_allocator(void) const
			{
				return (tree_.get_allocator());
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
			size_type erase(const value_type& value)
			{
				return (tree_.erase(value));
			}
			void erase(iterator first, iterator last)
			{
				tree_.erase(first, last);
			}
			void swap(set& s)
			{
				tree_.swap(s.tree_);
			}
			void clear(void)
			{
				tree_.clear();
			}
/*--------------------------------------------------------------------------*/
/*								L O O K U P									*/
/*--------------------------------------------------------------------------*/
			iterator find(const value_type& value) const
			{
				return (tree_.find(value));
			}
			size_type count(const value_type& value) const
			{
				return (!(find(value) == end()));
			}
			iterator lower_bound(const value_type& value) const
			{
				return (tree_.LowerBound(value));
			}
			iterator upper_bound(const value_type& value) const
			{
				return (tree_.UpperBound(value));
			}
			pair<iterator, iterator> equal_range(const value_type& value) const
			{
				return (tree_.EqualRange(value));
			}

/*--------------------------------------------------------------------------*/
/*								O B S E R V E R S							*/
/*--------------------------------------------------------------------------*/
			key_compare key_comp(void) const
			{
				return (comp_);
			}
			value_compare value_comp(void) const
			{
				return (comp_);
			}

		private:
			compare_type comp_;
			allocator_type alloc_;
			ft::RBTree<const value_type, key_type, value_compare, allocator_type> tree_;
	};

/*--------------------------------------------------------------------------*/
/*					N O N _ M E M B E R _ F U N C T I O N S					*/
/*--------------------------------------------------------------------------*/
	template <class T, class Compare, class Allocator>
	bool operator==(const ft::set<T, Compare, Allocator>& x, const ft::set<T, Compare, Allocator>& y)
	{
		return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <class T, class Compare, class Allocator>
	bool operator!=(const ft::set<T, Compare, Allocator>& x, const ft::set<T, Compare, Allocator>& y)
	{
		return (!(x == y));
	}

	template <class T, class Compare, class Allocator>
	bool operator<(const ft::set<T, Compare, Allocator>& x, const ft::set<T, Compare, Allocator>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	template <class T, class Compare, class Allocator>
	bool operator<=(const ft::set<T, Compare, Allocator>& x, const ft::set<T, Compare, Allocator>& y)
	{
		return (!(y < x));
	}

	template <class T, class Compare, class Allocator>
	bool operator>(const ft::set<T, Compare, Allocator>& x, const ft::set<T, Compare, Allocator>& y)
	{
		return (y < x);
	}

	template <class T, class Compare, class Allocator>
	bool operator>=(const ft::set<T, Compare, Allocator>& x, const ft::set<T, Compare, Allocator>& y)
	{
		return (!(x < y));
	}

	template <typename T, class Compare, class Allocator>
	void swap(ft::set<T, Compare, Allocator>& x, ft::set<T, Compare, Allocator>& y)
	{
		x.swap(y);
	}
}

#endif
