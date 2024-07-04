/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:05:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 17:08:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
: AMateria("cure")
{
	//std::cout << "Cure default constructor called" << std::endl;
}


Cure::Cure(const Cure &other)
: AMateria("cure")
{
	*this = other;
	//std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &other)
{
	(void)other;
	//std::cout << "Cure assignment operator called" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	//std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

/* void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<  "’s wounds *" << std::endl;
} */
		