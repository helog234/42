/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:07:11 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 16:28:53 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
:_name("")
{
	std::cout << "default constructor called" << std::endl;
}

Zombie::~Zombie() 
{
	std::cout << this->_name << " destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
	std::cout << "named : " <<_name << std::endl;
}
	
void	Zombie::announce( void ) const
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


	