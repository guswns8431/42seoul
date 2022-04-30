/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:00:26 by hyson             #+#    #+#             */
/*   Updated: 2022/04/30 18:24:06 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	//const Animal meta;

	std::cout << std::endl;
	j->makeSound();
	i->makeSound();
	//meta.makeSound();
	std::cout << std::endl;

	delete j;
	delete i;

	std::cout << std::endl;
	int animal_cnt = 6;
	std::cout << "[ Constructors of List ]" << std::endl;

	Animal *animal_list[animal_cnt];
	for (int i = 0; i < animal_cnt; i++)
	{
		if (i % 2 == 0)
			animal_list[i] = new Dog();
		else
			animal_list[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < animal_cnt; i++)
		animal_list[i]->makeSound();
	std::cout << std::endl;

	Dog *dg = new Dog();
	dg->getBrain()->setIdea("dog1");
	*(Dog *)animal_list[0] = *dg;
	delete dg;
	std::cout << std::endl;
	std::cout << "After delete dg class : " << ((Dog *)animal_list[0])->getBrain()->getIdea(1) <<std::endl;
	std::cout << std::endl;

	Dog nd = *(Dog *)animal_list[0];
	((Dog *)animal_list[0])->getBrain()->setIdea("dog1_new_idea");
	std::cout << std::endl;
	std::cout << "[ After set new idea in animal list ]" << std::endl;
	std::cout << ((Dog *)animal_list[0])->getBrain()->getIdea(1) << std::endl;
	std::cout << nd.getBrain()->getIdea(1) << std::endl;
	
	std::cout << std::endl;
	std::cout << "[ Print ideas ]" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << ((Dog *)animal_list[0])->getBrain()->getIdea(i) << std::endl;
		std::cout << nd.getBrain()->getIdea(i) << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Destructors of List ]" << std::endl;
	for (int i = 0; i < animal_cnt; i++)
		delete animal_list[i];
	return (0);
}
