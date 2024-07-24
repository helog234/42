/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:05:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 14:21:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
: AAnimal("Dog")
{
	_Brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	_type = other._type;
	_Brain = new Brain(*other._Brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		_type = other._type;
		delete _Brain;
		_Brain = new Brain(*other._Brain);
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete _Brain;
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType()
{
	return (AAnimal::getType());
}

void Dog::makeSound() const
{
	std::cout << "Waf waf" << std::endl;
	//Animal::makeSound();
}
