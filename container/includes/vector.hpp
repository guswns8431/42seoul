/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:59:05 by hyson             #+#    #+#             */
/*   Updated: 2022/09/22 19:03:59 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <limits>
# include <memory>
# include <stdexcept>
# include "algorithm.hpp"
# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "type_traits.hpp"

namespace ft
{

/*--------------------------------------------------------------------------*/
/*				        		V E C T O R									*/
/*--------------------------------------------------------------------------*/
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;

			typedef Allocator allocator_type;
			typedef typename allocator_type::template rebind<value_type>::other type_allocator;
			typedef std::allocator_traits<type_allocator> type_traits;
			typedef typename type_traits::pointer pointer;
			typedef typename type_traits::const_pointer const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;

			typedef typename std::size_t size_type;
			typedef typename std::ptrdiff_t difference_type;

			typedef ft::random_access_iterator<value_type> iterator;
			typedef ft::random_access_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

/*--------------------------------------------------------------------------*/
/*				C O N S T R U C T O R _ & _ D E S T R U C T O R				*/
/*--------------------------------------------------------------------------*/
			explicit vector(const allocator_type& alloc = allocator_type()): begin_(ft::nil), end_(ft::nil), cap_(ft::nil), alloc_(alloc) {}
			explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()) : alloc_(alloc)
			{
				Init(n);
				Construct(n, value);
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) : alloc_(alloc)
			{
				size_type n = std::distance(first, last);
				Init(n);
				Construct(n);
				std::copy(first, last, begin_);
			}
			vector(const vector& v) : alloc_(v.alloc_)
			{
				size_type n = v.size();
				Init(v.capacity());
				Construct(n);
				std::copy(v.begin_, v.end_, begin_);
			}
			~vector(void)
			{
				if (begin_ == ft::nil)
				{
					return ;
				}
				size_type pre_capacity = capacity();
				Destruct(begin_);
				alloc_.deallocate(begin_, pre_capacity);
			}

/*--------------------------------------------------------------------------*/
/*						M E M B E R _ F U N C T I O N						*/
/*--------------------------------------------------------------------------*/
			vector& operator=(const vector& v)
			{
				if (this != &v)
				{
					assign(v.begin_, v.end_);
				}
				return (*this);
			}
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
			{
				size_type n = std::distance(first, last);
				if (capacity() < n)
				{
					reserve(n);
				}
				std::copy(first, last, begin_);
				end_ = begin_ + n;
			}
			void assign(size_type n, const value_type& value)
			{
				if (capacity() < n)
				{
					reserve(n);
				}
				std::fill_n(begin_, n, value);
				end_ = begin_ + n;
			}
			allocator_type get_allocator(void) const
			{
				return (alloc_);
			}
/*--------------------------------------------------------------------------*/
/*						E L E M E N T _ A C C E S S							*/
/*--------------------------------------------------------------------------*/
			reference operator[](size_type n)
			{
				return (begin_[n]);
			}
			const_reference operator[](size_type n) const
			{
				return (begin_[n]);
			}
			reference at(size_type n)
			{
				if (n >= size())
				{
					throw std::out_of_range("index out of range");
				}
				return (begin_[n]);
			}
			const_reference at(size_type n) const
			{
				if (n >= size())
				{
					throw std::out_of_range("index out of range");
				}
				return (begin_[n]);
			}
			reference front(void)
			{
				return *begin_;
			}
			const_reference front(void) const
			{
				return (*begin_);
			}
			reference back(void)
			{
				return (*(end_ - 1));
			}
			const_reference back(void) const
			{
				return (*(end_ - 1));
			}
			T* data(void)
			{
				return (reinterpret_cast<T*>(begin_));
			}
			const T* data(void) const
			{
				return (reinterpret_cast<const T*>(begin_));
			}
/*--------------------------------------------------------------------------*/
/*								I T E R A T O R								*/
/*--------------------------------------------------------------------------*/
			iterator begin(void)
			{
				return (iterator(begin_));
			}
			const_iterator begin(void) const
			{
				return (const_iterator(begin_));
			}
			iterator end(void)
			{
				return (iterator(end_));
			}
			const_iterator end(void) const
			{
				return (const_iterator(end_));
			}
			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(end()));
			}
			reverse_iterator rend(void)
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(begin()));
			}
/*--------------------------------------------------------------------------*/
/*								C A P A C I T Y								*/
/*--------------------------------------------------------------------------*/
			bool empty(void) const { return (begin_ == end_); }
			size_type size(void) const
			{
				return (static_cast<size_type>(end_ - begin_));
			}
			size_type max_size(void) const
			{
				return (std::min<size_type>(std::numeric_limits<size_type>::max(), type_traits::max_size(type_allocator())));
			}
			void reserve(size_type n)
			{
				if (n <= size() || n <= capacity())
				{
					return ;
				}
				if (n < capacity() * 2)
				{
					n = capacity() * 2;
				}
				size_type pre_size = size();
				size_type pre_capacity = capacity();
				pointer begin = alloc_.allocate(n);
				std::uninitialized_copy(begin_, end_, begin);
				Destruct(begin_);
				alloc_.deallocate(begin_, pre_capacity);
				begin_ = begin;
				end_ = begin_ + pre_size;
				cap_ = begin_ + n;
			}
			size_type capacity(void) const
			{
				return (static_cast<size_type>(cap_ - begin_));
			}
/*--------------------------------------------------------------------------*/
/*							M O D I F I E R	S								*/
/*--------------------------------------------------------------------------*/
			void clear(void)
			{
				Destruct(begin_);
			}

			iterator insert(iterator position, const value_type& value)
			{
				difference_type diff = position - begin();
				if (capacity() < size() + 1)
				{
					reserve(size() + 1);
				}
				pointer ptr = begin_ + diff;
				Construct(1);
				std::copy_backward(ptr, end_ - 1, end_);
				*ptr = value;
				return (iterator(ptr));
			}
			void insert(iterator position, size_type n, const value_type& value)
			{
				difference_type diff = position - begin();
				if (capacity() < size() + n)
				{
					reserve(size() + n);
				}
				pointer ptr = begin_ + diff;
				Construct(n);
				std::copy_backward(ptr, end_ - n, end_);
				for (size_type i = 0 ; i < n ; i++)
				{
					ptr[i] = value;
				}
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
			{
				difference_type n = std::distance(first, last);
				difference_type diff = position - begin();
				if (capacity() < size() + n)
				{
					reserve(size() + n);
				}
				pointer ptr = begin_ + diff;
				Construct(n);
				std::copy_backward(ptr, end_ - n, end_);
				for (InputIterator i = first ; i != last ; i++, ptr++)
				{
					*ptr = *i;
				}
			}
			iterator erase(iterator position)
			{
				difference_type diff = position - begin();
				pointer ptr = begin_ + diff;
				std::copy(ptr + 1, end_, ptr);
				Destruct(1);
				return (iterator(ptr));
			}
			iterator erase(iterator first, iterator last)
			{
				difference_type n = std::distance(first, last);
				std::copy(last, end(), first);
				Destruct(n);
				return (first);
			}
			void push_back(const value_type& value)
			{
				size_type n = size() + 1;
				if (capacity() < n)
				{
					reserve(n);
				}
				Construct(1);
				*(end_ - 1) = value;
			}
			void pop_back(void)
			{
				Destruct(1);
			}
			void resize(size_type n, value_type value = value_type())
			{
				if (size() > n)
				{
					size_type diff = size() - n;
					Destruct(diff);
				}
				else if (size() < n)
				{
					size_type diff = n - size();
					if (capacity() < n)
					{
						reserve(n);
					}
					Construct(diff, value);
				}
			}
			void swap(vector& v)
			{
				std::swap(begin_, v.begin_);
				std::swap(end_, v.end_);
				std::swap(cap_, v.cap_);
				std::swap(alloc_, v.alloc_);
			}
		private:
			pointer			begin_;
			pointer			end_;
			pointer			cap_;
			allocator_type	alloc_;

			void Init(size_type n)
			{
				if (n > max_size())
				{
					throw std::length_error("allocation size too big");
				}
				begin_ = alloc_.allocate(n);
				end_ = begin_;
				cap_ = begin_ + n;
			}

			void Construct(size_type n, T value)
			{
				for ( ; n > 0 ; end_++, n--)
				{
					alloc_.construct(end_);
					*end_ = value;
				}
			}

			void Construct(size_type n)
			{
				for ( ; n > 0 ; end_++, n--)
				{
					alloc_.construct(end_);
				}
			}

			void Destruct(size_type n)
			{
				for ( ; n > 0 && end_-- ; n--)
				{
					alloc_.destroy(end_);
				}
			}

			void Destruct(pointer until)
			{
				for ( ; end_ != until && end_-- ; )
				{
					alloc_.destroy(end_);
				}
			}
	};
/*--------------------------------------------------------------------------*/
/*					N O N _ M E M B E R _ F U N C T I O N S					*/
/*--------------------------------------------------------------------------*/

	template <typename T, class Allocator>
	bool operator==(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y)
	{
		return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <typename T, class Allocator>
	bool operator!=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y)
	{
		return (!(x == y));
	}

	template <typename T, class Allocator>
	bool operator<(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	template <typename T, class Allocator>
	bool operator<=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y)
	{
		return (x == y || x < y);
	}

	template <typename T, class Allocator>
	bool operator>(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y)
	{
		return (!(x <= y));
	}

	template <typename T, class Allocator>
	bool operator>=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y)
	{
		return (x == y || x > y);
	}

	template <typename T, class Allocator>
	void swap(ft::vector<T, Allocator>& x, ft::vector<T, Allocator>& y)
	{
		x.swap(y);
	}
}

#endif
