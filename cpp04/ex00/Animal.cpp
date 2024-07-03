/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:59:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 14:16:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
: _type(type)
{
	std::cout << "Animal default constructor called with type" << std::endl;
}
Animal::Animal(const Animal& other)
{
	_type = other._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
	std::cout << "Animal assignment operator called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	if (_type == "Dog")
		std::cout << "Waf waf" << std::endl;
	else if (_type == "Cat")
		std::cout << "Miaou miaou" << std::endl;
}