/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:59:05 by hyson             #+#    #+#             */
/*   Updated: 2022/09/08 21:24:44 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
//COMMENT numeric_limits
# include <limits>
//COMMENT allocator, uninitialized_copy
# include <memory>
//COMMENT std::out_of_range
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
			//FIXED type_allocator를 지우고 Allocator로 바꿔야하나?
			//TODO rebind는 벡터에선 안 써도 됨, rebind가 무엇인지 더 알아볼 필요 있을듯
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
			explicit vector(const allocator_type& alloc = allocator_type()): __begin(ft::nil), __end(ft::nil), __cap(ft::nil), __alloc(alloc) {} //TODO nil에 대해서 고민
			explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()) : __alloc(alloc)
			{
				__init(n);
				__construct(n, value);
			}
			template <class InputIterator>
			//COMMENT enable_if에 숫자가 들어가 가면 안 되기 때문에 is_ingral이 나오면 !를 통해서 false가 됨
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) : __alloc(alloc)
			{
				size_type n = std::distance(first, last);
				__init(n);
				__construct(n);
				std::copy(first, last, __begin);
			}
			vector(const vector& v) : __alloc(v.__alloc)
			{
				size_type n = v.size();
				__init(v.capacity());
				__construct(n);
				std::copy(v.__begin, v.__end, __begin);
			}
			//COMMENT allocate조차 하지 못 했을땐, begin이 nil이라 return
			~vector(void)
			{
				if (__begin == ft::nil)
				{
					return ;
				}
				size_type pre_capacity = capacity();
				__destruct(__begin);
				__alloc.deallocate(__begin, pre_capacity);
			}

/*--------------------------------------------------------------------------*/
/*						M E M B E R _ F U N C T I O N						*/
/*--------------------------------------------------------------------------*/
			vector& operator=(const vector& v)
			{
				if (this != &v)
				{
					assign(v.__begin, v.__end);
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
				std::copy(first, last, __begin);
				__end = __begin + n;
			}
			void assign(size_type n, const value_type& value)
			{
				if (capacity() < n)
				{
					reserve(n);
				}
				std::fill_n(__begin, n, value);
				__end = __begin + n;
			}
			//COMMENT allocator를 받아와서 custom을 할때 필요하지 않을까
			allocator_type get_allocator(void) const
			{
				return (__alloc);
			}
/*--------------------------------------------------------------------------*/
/*						E L E M E N T _ A C C E S S							*/
/*--------------------------------------------------------------------------*/
			//COMMENT at과의 다른점. []연산은 범위에 관한 예외처리를 해주지 않음
			reference operator[](size_type n)
			{
				return (__begin[n]);
			}
			const_reference operator[](size_type n) const
			{
				return (__begin[n]);
			}
			reference at(size_type n)
			{
				if (n >= size())
				{
					throw std::out_of_range("index out of range");
				}
				return (__begin[n]);
			}
			const_reference at(size_type n) const
			{
				if (n >= size())
				{
					throw std::out_of_range("index out of range");
				}
				return (__begin[n]);
			}
			reference front(void)
			{
				return *__begin;
			}
			const_reference front(void) const
			{
				return (*__begin);
			}
			//COMMENT __end는 배열의 끝 다음을 가리키기 때문에 그 전을 뽑아주기 위해선 -1
			reference back(void)
			{
				return (*(__end - 1));
			}
			const_reference back(void) const
			{
				return (*(__end - 1));
			}
			//COMMENT 첫 데이터의 주소값 리턴
			//어차피 iterator도 pointer이기 때문에 직접 그 위치를 받아올 수는 있지만, 안전하게 reinterpret_cast를 통해서 원본을 가져오자
			T* data(void) throw()
			{
				return (reinterpret_cast<T*>(__begin));
			}
			const T* data(void) const throw()
			{
				return (reinterpret_cast<const T*>(__begin));
			}
/*--------------------------------------------------------------------------*/
/*								I T E R A T O R								*/
/*--------------------------------------------------------------------------*/
			iterator begin(void)
			{
				return (iterator(__begin));
			}
			const_iterator begin(void) const
			{
				return (const_iterator(__begin));
			}
			iterator end(void)
			{
				return (iterator(__end));
			}
			const_iterator end(void) const
			{
				return (const_iterator(__end));
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
			bool empty(void) const { return (__begin == __end); }
			size_type size(void) const
			{
				return (static_cast<size_type>(__end - __begin));
			}
			//COMMENT max_size vector가 할당될 수 있는 최대 크기 return
			//자료형 최대와 할당할 수 있는 크기의 최대를 비교하여 둘 중 최소값을 찾으면 그것이 할당될 수 있는 최대크기
			size_type max_size(void) const
			{
				return (std::min<size_type>(std::numeric_limits<size_type>::max(), type_traits::max_size(type_allocator())));
			}
			void reserve(size_type n)
			{
				//TODO n <= size()가 없어도 되나?? 어차피 size()가 capacity()보다 클 리가 없음
				//COMMENT reserve는 resize와 다르게 재지정할 크기가 현재보다 작으면 아무런 작업을 하지 않음
				if (n <= size() || n <= capacity())
				{
					return ;
				}
				//COMMENT 2배 공간 할당 할 수 있는지 보고 할당
				if (n < capacity() * 2)
				{
					n = capacity() * 2;
				}
				size_type pre_size = size();
				size_type pre_capacity = capacity();
				pointer begin = __alloc.allocate(n);
				//COMMENT copy와 다른것은 copy는 그냥 값 복사, uninitialized_copy를 하면 생성자 호출
				//new 과정이 일어남. 위에서 공간을 할당을 해줬기 때문에 new가 일어나면 공간할당은 이미 되어 있어 그 과정은 넘어가고 생성자 호출
				//만약 불러오는 녀석이 상속이 되어 있는 경우, 생성자를 호출해서 가져오면 잘 가져오는데 그게 아니면, 상속된 녀석들은 공간할당이 안 되기 때문에 문제 발생
				std::uninitialized_copy(__begin, __end, begin);
				__destruct(__begin);
				__alloc.deallocate(__begin, pre_capacity);
				__begin = begin;
				__end = __begin + pre_size;
				__cap = __begin + n;
			}
			size_type capacity(void) const
			{
				return (static_cast<size_type>(__cap - __begin));
			}
/*--------------------------------------------------------------------------*/
/*							M O D I F I E R	S								*/
/*--------------------------------------------------------------------------*/
			void clear(void)
			{
				__destruct(__begin);
			}

			iterator insert(iterator position, const value_type& value)
			{
				//COMMENT begin(), __begin 사용의 차이
				// begin()은 iterator, __begin은 포인터. 따라서 자료형을 같게 하기 위해 사용.
				difference_type diff = position - begin();
				if (capacity() < size() + 1)
				{
					reserve(size() + 1);
				}
				pointer ptr = __begin + diff;
				__construct(1);
				//COMMENT copy는 first에서부터 시작해서 last로 이동하면서 한 요소씩 순서대로 복사하는데,
				//원본과 목적 구간이 겹쳐 있으면 원본이 앞쪽 복사에 의해 읽기도 전에 파괴되는 문제가 있다.
				//그래서 역방향으로 진행하면서 복사하는 copy_backward 함수가 따로 마련됨
				//복사를 시작할 위치 ptr, 복사를 끝낼 위치 __end - 1, 새롭게 복사를 할 위치 __end(끝에서부터 복사를 함)
				//넣을 위치 공간을 찾고 먼저 그 공간뒤까지 맨 뒤에서부터 복사를 함
				//넣을 위치 값 넣고 반환
				std::copy_backward(ptr, __end - 1, __end);
				*ptr = value;
				return (iterator(ptr));
			}
			//COMMENT n크기만큼 value를 넣어줌
			void insert(iterator position, size_type n, const value_type& value)
			{
				difference_type diff = position - begin();
				if (capacity() < size() + n)
				{
					reserve(size() + n);
				}
				pointer ptr = __begin + diff;
				__construct(n);
				std::copy_backward(ptr, __end - n, __end);
				for (size_type i = 0 ; i < n ; i++)
				{
					ptr[i] = value;
				}
			}
			//COMMENT first, last 범위에 넣어줌
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
			{
				difference_type n = std::distance(first, last);
				difference_type diff = position - begin();
				if (capacity() < size() + n)
				{
					reserve(size() + n);
				}
				pointer ptr = __begin + diff;
				__construct(n);
				std::copy_backward(ptr, __end - n, __end);
				for (InputIterator i = first ; i != last ; i++, ptr++)
				{
					*ptr = *i;
				}
			}
			//COMMENT 특정 위치를 제거
			iterator erase(iterator position)
			{
				difference_type diff = position - begin();
				pointer ptr = __begin + diff;
				//COMMENT 매개변수 통일이 되어야 하기 때문에, ptr여서 __end(포인터)를 넣어줌
				std::copy(ptr + 1, __end, ptr);
				__destruct(1);
				return (iterator(ptr));
			}
			//COMMENT 범위를 지울거기 때문에 first위치에 last 다음 녀석이 옴
			iterator erase(iterator first, iterator last)
			{
				difference_type n = std::distance(first, last);
				//COMMENT 매개변수 통일이 되어야 하기 때문에, last가 iterator라서 iterator로 통일
				std::copy(last, end(), first);
				__destruct(n);
				return (first);
			}
			//COMMENT 공간 부족하면 reserve로 공간 2배 할당 후 맨뒤에 값 넣어줌
			void push_back(const value_type& value)
			{
				size_type n = size() + 1;
				if (capacity() < n)
				{
					reserve(n);
				}
				__construct(1);
				*(__end - 1) = value;
			}
			void pop_back(void)
			{
				__destruct(1);
			}
			void resize(size_type n, value_type value = value_type())
			{
				//COMMENT 새로 늘리려는 크기 n이 원래 사이즈보다 작다면 잘라야 작은만큼은 잘라냄.
				if (size() > n)
				{
					size_type diff = size() - n;
					__destruct(diff);
				}
				else if (size() < n)
				{
					size_type diff = n - size();
					if (capacity() < n)
					{
						reserve(n);
					}
					__construct(diff, value);
				}
			}
			void swap(vector& v)
			{
				std::swap(__begin, v.__begin);
				std::swap(__end, v.__end);
				std::swap(__cap, v.__cap);
				std::swap(__alloc, v.__alloc);
			}
		private:
			pointer			__begin;
			pointer			__end;
			pointer			__cap;
			allocator_type	__alloc;

			//COMMENT 벡터 생성할때 초기화
			//__begin에 시작지점
			//__end에 아직 공간 할당이 되기 전이기 때문에 __begin과 같은 위치
			//__cap 공간
			void __init(size_type n)
			{
				if (n > max_size())
				{
					throw std::length_error("allocation size too big");
				}
				__begin = __alloc.allocate(n);
				__end = __begin;
				__cap = __begin + n;
			}

			//COMMENT 공간을 늘려가면서 value값 초기화
			//construct()는 replacement new를 사용하여 확보한 메모리 공간에 개체를 실제로 생성하여 배치하는 역할을 한다 출처: https://celdee.tistory.com/790
			void __construct(size_type n, T value)
			{
				for ( ; n > 0 ; __end++, n--)
				{
					__alloc.construct(__end);
					*__end = value;
				}
			}

			//COMMENT 공간을 할당만함
			void __construct(size_type n)
			{
				for ( ; n > 0 ; __end++, n--)
				{
					__alloc.construct(__end);
				}
			}

			void __destruct(size_type n)
			{
				for ( ; n > 0 && __end-- ; n--)
				{
					__alloc.destroy(__end);
				}
			}

			void __destruct(pointer until)
			{
				for ( ; __end != until && __end-- ; )
				{
					__alloc.destroy(__end);
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
