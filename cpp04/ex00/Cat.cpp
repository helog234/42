/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:08:16 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 16:31:38 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
: Animal(other)
{
	_type = other._type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType()
{
	return (Animal::getType());
}

void Cat::makeSound()
{
	Animal::makeSound();
}
