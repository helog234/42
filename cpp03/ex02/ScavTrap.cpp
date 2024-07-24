/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:55:47 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 15:22:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name)
: ClapTrap(Name)
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &other)
: ClapTrap(other)
{
	_HitPoints =other._HitPoints;
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
	if (_EnergyPoints <= 0 || _HitPoints <= 0)
	{
		std::cout << "ScavTrap " << _Name;
		std::cout << " has not energy points to attack" << std::endl;
		return ;
	}
		
	std::cout << "ScavTrap " << _Name;
	std::cout << " attacks " << target << std::endl;
	_EnergyPoints--;
	_HitPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _Name;
	std::cout << " is in Gatekeeper mode." << std::endl;
}
