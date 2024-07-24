/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:08:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 15:23:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
:_Name(Name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
	{
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (_EnergyPoints <= 0 || _HitPoints <= 0)
	{
		std::cout << "ClapTrap " << _Name;
		std::cout << " has not energy or hit point points to attack" << std::endl;
		return ;
	}
		
	std::cout << "ClapTrap " << _Name;
	std::cout << " attacks " << target << std::endl;
	_EnergyPoints--;
}
	
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _Name;
	std::cout << " is attacked " << "costing ";
	std::cout << amount << " Attack damage" << std::endl;
	_HitPoints -= amount;
	_AttackDamage -= amount;
	if (_AttackDamage < 0)
		_AttackDamage = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0 || _HitPoints <= 0)
	{
		std::cout << "ClapTrap " << _Name;
		std::cout << " has not energy points to repair" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _Name;
	std::cout << " repairs itself " << "costing ";
	std::cout << "1 Hit point" << std::endl;
	_EnergyPoints--;
	_HitPoints +=amount;
}
void ClapTrap::displayInfo(void)
{
	
	std::cout << this->_Name << " has ";
	std::cout << this->_HitPoints << " hit points left ";
	std::cout << this->_EnergyPoints << " Energy points left ";
	std::cout << this->_AttackDamage << " Attack damage left" << std::endl;
}
