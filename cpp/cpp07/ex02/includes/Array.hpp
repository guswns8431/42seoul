/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:27:59 by hyson             #+#    #+#             */
/*   Updated: 2022/05/15 01:19:06 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# define RED		"\033[0;31m"
# define YELLOW		"\033[0;33m"
# define PURPLE		"\033[0;35m"
# define EOC		"\033[0;0m"

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
			if (this != &a)
			{
				if (this->array_ != NULL)
				{
					delete[] this->array_;
					this->array_ = NULL;
					this->size_ = 0;
				}
				this->size_ = a.size_;
				this->array_ = new T[a.size_];
				for (unsigned int i = 0; i < a.size_; i++)
					this->array_[i] = a.array_[i];
			}
			return (*this);
		};
		T&		operator[](unsigned int i)
		{
			if (this->size_ <= i)
				throw OutOfBoundsException();
			return (this->array_[i]);
		}
		const T&	operator[](unsigned int i) const
		{
			if (this->size_ <= i)
				throw OutOfBoundsException();
			return (this->array_[i]);
		}
		~Array(void)
		{
			if (this->array_ != NULL)
			{
				delete[] this->array_;
				this->array_ = NULL;
				this->size_ = 0;
			}
		}
		unsigned int size(void) const
		{
			return (this->size_);
		}
};

template <typename T>
std::ostream&	operator<<(std::ostream& o, const Array<T>& a)
{
	unsigned int count = 0;
	for (unsigned int i = 0; i < a.size(); i++)
	{
		o << a[i] << " ";
		count++;
		if (count == 5)
		{
			std::cout << std::endl;
			count = 0;
		}
	}
		
	return (o);
}

#endif
