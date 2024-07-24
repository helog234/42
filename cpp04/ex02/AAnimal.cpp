/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:59:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 14:22:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
: _type(type)
{
	std::cout << "AAnimal default constructor called with type" << std::endl;
}
AAnimal::AAnimal(const AAnimal& other)
{
	_type = other._type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "AAnimal assignment operator called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return (_type);
}
