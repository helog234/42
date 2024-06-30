/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:07:11 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/24 11:03:48 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
:_name("")
{}
Zombie::Zombie(std::string name) 
: _name(name)
{
	std::cout << name << " created" << std::endl;
}

Zombie::~Zombie() 
{
	std::cout << this->_name << " destroyed" << std::endl;
}
	
void	Zombie::announce( void )
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
	
	