/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:08:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/12 14:33:05 by hgandar          ###   ########.fr       */
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
: _Name(other._Name), _HitPoints(other._HitPoints), 
_EnergyPoints(other._HitPoints), _AttackDamage(other._AttackDamage)
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
		_EnergyPoints = other._EnergyPoints;
		_HitPoints = other._HitPoints;
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
		std::cout << " has not energy points to attack";
		return ;
	}
		
	std::cout << "ClapTrap " << _Name;
	std::cout << " attacks " << target;
	_EnergyPoints--;
	_HitPoints--;
}
	
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _Name;
	std::cout << " is attacked " << "costing ";
	std::cout << amount << " Attack damage" << std::endl;
	_HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0 || _HitPoints <= 0)
	{
		std::cout << "ClapTrap " << _Name;
		std::cout << " has not energy points to repair";
		return ;
	}
	std::cout << "ClapTrap " << _Name;
	std::cout << " repairs itself " << "costing ";
	std::cout << " 1 energy point" << std::endl;
	_EnergyPoints--;
	_HitPoints +=amount;
}
void ClapTrap::displayInfo(void) const
{
	
	std::cout << _Name << " has ";
	std::cout << _HitPoints << " hit points left ";
	std::cout << _EnergyPoints << " Energy points left ";
	std::cout << _AttackDamage << " Attack damage left" << std::endl;
}
