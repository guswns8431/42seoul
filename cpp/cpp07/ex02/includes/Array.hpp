/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:27:59 by hyson             #+#    #+#             */
/*   Updated: 2022/05/14 23:21:03 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class	Array {
	private:
		T*	array_;
		unsigned int size_;
	public:
		class OutOfBoundsException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return "Out of bounds";
			}
		};
		Array(void)
		{
			this->array_ = new T[0];
			this->size_ = 0;
		};
		Array(unsigned int n)
		{
			this->array_ = new T[n];
			this->size_ = n;
		};
		Array(const Array& a)
		{
			this->size_ = a.size_;
			this->array_ = new T[a.size()];
			for (unsigned int i = 0; i < a.size(); i++)
				this->array_[i] = a[i];
		};
		Array<T>& operator=(const Array& a)
		{
			this->size_ = a.size_;
			this->array_ = new T[this->size_];
			for (unsigned int i = 0; i < this->size_; i++)
				this->array_[i] = a.array_[i];
			return (*this);
		};
		T&		operator[](unsigned int i)
		{
			if (this->size_ <= i)
				throw OutOfBoundsException();
			return (this->array_[i]);
		}
		T&		operator[](unsigned int i) const
		{
			if (this->size_ <= i)
				throw OutOfBoundsException();
			return (this->array_[i]);
		}
		~Array(void)
		{
			delete[] this->array_;
		}
		unsigned int size(void) const
		{
			return (this->size_);
		}
};

template <typename T>
std::ostream&	operator<<(std::ostream& o, const Array<T>& a)
{
	for (unsigned int i = 0; i < a.size(); i++)
		o << a[i] << " ";
	return (o);
}

#endif
