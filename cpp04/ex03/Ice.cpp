/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:02:05 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 13:03:47 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
Ice::Ice()
: AMateria("ice")
{
	//std::cout << "Ice default constructor called" << std::endl;
}

/* Ice::Ice(std::string const & type)
: _type(type)
{
	std::cout << "Ice default constructor called" << std::endl;

} */

Ice::Ice(const Ice &other)
: AMateria("ice")
{
	*this = other;
	//std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	(void)other;
	//std::cout << "Ice assignment operator called" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	//std::cout << "Ice destructor called" << std::endl;
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

/* void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
} */
