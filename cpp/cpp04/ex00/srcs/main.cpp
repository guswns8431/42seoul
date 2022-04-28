/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:00:26 by hyson             #+#    #+#             */
/*   Updated: 2022/04/28 21:08:10 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongCat* wc = new WrongCat();
	const WrongAnimal* wac = new WrongCat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	std::cout << wmeta->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	std::cout << wac->getType() << " " << std::endl;
	
    meta->makeSound();
	j->makeSound();
	i->makeSound();
	wmeta->makeSound();
	wc->makeSound();
	wac->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wmeta;
	delete wc;
	delete wac;
	return 0; 
}
