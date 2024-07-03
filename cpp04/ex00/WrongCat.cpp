/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:24:03 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 14:26:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other)
{
	_type = other._type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "WrongCat assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType()
{
	return (WrongAnimal::getType());
}

void WrongCat::makeSound()
{
	WrongAnimal::makeSound();
}