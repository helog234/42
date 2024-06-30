/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:13:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/24 10:26:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) 
: _name(name)
{
	std::cout << name << " created" << std::endl;
}

Zombie::~Zombie() 
{
	std::cout << this->_name << " deleted" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name )
{
	Zombie *instance = new Zombie(name);
	return (instance);
}