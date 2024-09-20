/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:13:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 15:43:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) 
: _name(name)
{
	std::cout << _name << " created" << std::endl;
}

Zombie::~Zombie() 
{
	std::cout << _name << " deleted" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << _name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

