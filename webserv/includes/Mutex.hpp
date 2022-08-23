/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutex.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:50:20 by hyson             #+#    #+#             */
/*   Updated: 2022/08/17 18:50:58 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_HPP
# define MUTEX_HPP

# include <pthread.h>

class Mutex
{
private:
	pthread_mutex_t _mutex;
	Mutex(const Mutex &m);
	Mutex &operator=(const Mutex &m);

public:
	Mutex(void);
	~Mutex(void);

	void lock(void);
	void unlock(void);
	bool try_lock(void);
};

#endif
