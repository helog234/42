/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:47:05 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 12:57:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* AMateria::AMateria()
: _type("hola")
{
	std::cout << "AMateria default constructor called" << std::endl;
} */

AMateria::AMateria(std::string const & type)
: _type(type)
{
	//std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
: _type(other._type)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_type = other._type;
	//std::cout << "AMateria assignment operator called" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

AMateria* AMateria::clone() const
{
	return ((AMateria*)this);
	//return (new this->AMateria::AMateria(getType()));
}

void AMateria::use(ICharacter& target)
{
	//std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	if (this->_type == "cure")
		std::cout << "* heals " << target.getName() <<  "’s wounds *" << std::endl;
}