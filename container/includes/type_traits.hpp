/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:09:25 by hyson             #+#    #+#             */
/*   Updated: 2022/09/22 18:54:56 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <cstdint>

namespace ft
{

const class nullptr_t
{
	private:
		void operator&(void) const;

	public:
		template <typename T>
		operator T*(void) const
		{
			return (0);
		}

		template <typename T, typename U>
  		operator T U::*(void) const
		{
			return (0);
		}
} nil;

/*------------------------------------------------------------------------------*/
/*								E N A B L E _ I F								*/
/*------------------------------------------------------------------------------*/

	template <bool, typename = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

/*------------------------------------------------------------------------------*/
/*						I N T E G R A L _ C O N S T A N T						*/
/*------------------------------------------------------------------------------*/

	template <typename T, T v>
	struct integral_constant
	{
	  	typedef T value_type;
 		typedef integral_constant type;
  		static const value_type value = v;
  		operator value_type(void) const
		{
			return (value);
		}
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

/*------------------------------------------------------------------------------*/
/*								R E M O V E _ C V								*/
/*------------------------------------------------------------------------------*/

	template <typename T>
	struct remove_cv { typedef T type; };

	template <typename T>
	struct remove_cv<const T> { typedef T type; };

	template <typename T>
	struct remove_cv<volatile T> { typedef T type; };

	template <typename T>
	struct remove_cv<const volatile T> { typedef T type; };

/*------------------------------------------------------------------------------*/
/*								I S _ I N T E G R A L							*/
/*------------------------------------------------------------------------------*/

	template <typename>
	struct is_integral_base : public false_type {};

	template <>
	struct is_integral_base<bool> : public true_type {};

	template <>
	struct is_integral_base<std::int8_t> : public true_type {};

	template <>
	struct is_integral_base<std::uint8_t> : public true_type {};

	template <>
	struct is_integral_base<std::int16_t> : public true_type {};

	template <>
	struct is_integral_base<std::uint16_t> : public true_type {};

	template <>
	struct is_integral_base<std::int32_t> : public true_type {};

	template <>
	struct is_integral_base<std::uint32_t> : public true_type {};

	template <>
	struct is_integral_base<std::int64_t> : public true_type {};

	template <>
	struct is_integral_base<std::uint64_t> : public true_type {};

	template <typename T>
	struct is_integral : public is_integral_base<typename remove_cv<T>::type> {};
}

#endif
