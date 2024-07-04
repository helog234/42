/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:59:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 16:59:01 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

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
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}
