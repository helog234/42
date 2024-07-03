/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:55:47 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 13:14:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void)
: ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    return ;
}

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
{
	_Name = other._Name;
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
	{
		_Name = other._Name;
		_EnergyPoints = other._EnergyPoints;
		_HitPoints = other._HitPoints;
		_AttackDamage = other._AttackDamage;
		
	}
    return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void)
{
	//~ClapTrap();
    std::cout << "ScavTrap destructor called" << std::endl;
    return ;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_Name;
		std::cout << " has not energy points to attack";
		return ;
	}
		
	std::cout << "ScavTrap " << this->_Name;
	std::cout << " attacks " << target;
	std::cout << " causing " << "2 " << "points of damage!" <<std::endl;
	this->_EnergyPoints--;
	this->_HitPoints--;
	(void)_AttackDamage;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_Name;
	std::cout << " is in Gatekeeper mode." << std::endl;
}
