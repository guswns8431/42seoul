/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LockGuard.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:45:17 by hyson             #+#    #+#             */
/*   Updated: 2022/08/17 18:46:08 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCKGUARD_HPP
# define LOCKGUARD_HPP

# include "./Mutex.hpp"

template <typename T>
class LockGuard
{
private:
	T *_mutex;

	LockGuard(void);
	LockGuard(const LockGuard &g);
	LockGuard &operator=(const LockGuard &g);

public:
	explicit LockGuard(T *mutex)
	{
		_mutex = mutex;
		_mutex->lock();
	}

	~LockGuard(void)
	{
		_mutex->unlock();
	}
};

#endif
