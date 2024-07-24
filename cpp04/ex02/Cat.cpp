/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:08:16 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 14:22:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
: AAnimal("Cat")
{
	_Brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& other)
{
	_type = other._type;
	_Brain = new Brain(*other._Brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		_type = other._type;
		delete _Brain;
		_Brain = new Brain(*other._Brain);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete _Brain;
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType()
{
	return (AAnimal::getType());
}

void Cat::makeSound() const
{
	std::cout << "Miaou miaou" << std::endl;
	//Animal::makeSound();
}
