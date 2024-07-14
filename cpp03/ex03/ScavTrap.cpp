/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:55:47 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/14 16:41:22 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
:  ClapTrap("ScavTrap", _initHit, _initEnergy, _initAttack) 
{
	 std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name)
: ClapTrap(Name, _initHit, _initEnergy, _initAttack)
{
    std::cout << "ScavTrap default constructor called" << std::endl;

    return ;
}

ScavTrap::ScavTrap(const ScavTrap &other)
: ClapTrap(other)
{
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._HitPoints;
	_AttackDamage = other._AttackDamage;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
    return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
    return ;
}

void ScavTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_Name;
	std::cout << " is in Gatekeeper mode." << std::endl;
}
