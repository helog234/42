/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:04:26 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/24 15:45:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

std::string HumanA::getName() const
{
	return (_name);
}

void HumanA::attack() const
{
	std::cout << this->_name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}