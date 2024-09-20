/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:30:14 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 16:47:50 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string& name)
: _name(name), _weapon(nullptr) {}

HumanB::HumanB(const std::string& name, Weapon* weapon)
: _name(name), _weapon(weapon) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& type)
{
	this->_weapon = &type;
}

std::string HumanB::getName() const
{
	return (_name);
}

void HumanB::attack() const
{
	if (_weapon)
	{
		std::cout << this->_name << " attacks with their ";
		std::cout << _weapon->getType() << std::endl;
	}
	else
		std::cout << this->_name << " is unarmed " << std::endl;
}

