/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:52:41 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 14:23:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int	n = 6;
	const AAnimal* block[n];
	// const  AAnimal *d = new test();
	// test->makeSound();
	for (size_t i = 0; i < n; i++)
	{
		if (i < n/2)
			block[i] = new Dog();
		else
			block[i] = new Cat();
	}
	for (size_t i = 0; i < n; i++)
	{
		std::cout << block[i]->getType() << " " << ": ";
		block[i]->makeSound();
	}
	for (size_t i = 0; i < n; i++)
		delete block[i];
	
	return 0;
}