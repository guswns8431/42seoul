/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:00:26 by hyson             #+#    #+#             */
/*   Updated: 2022/04/29 22:20:05 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

/*
int main(void)
{
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	const Animal* ci = new Dog();
	const Animal* cj = new Cat();
	Dog d;
	Dog cd;

	std::cout << "copy start" << std::endl;
	d = cd;

	i = ci;
	j = cj;
	std::cout << "copy end" << std::endl;

	std::cout << "delete1" << std::endl;
	delete i;
	std::cout << "delete2" << std::endl;
	delete j;
	std::cout << "delete3" << std::endl;
	delete ci;
	std::cout << "delete4" << std::endl;
	delete cj;
	std::cout << "delete5" << std::endl;

	return (0);
}
*/


int main() {
    const Animal* animals[10];

    for (int i = 0 ; i < 10 ; i++) {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0 ; i < 10 ; i++)
        animals[i]->makeSound();


    Dog dog1;
    Dog dog2;
    Dog dog3(dog1);
	Cat Cat1;

    dog2 = dog1;
}
