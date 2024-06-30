/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:20:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/30 14:10:38 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(void)
: ClapTrap()
{
    std::cout << " FragTrap default constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(std::string Name)
: ClapTrap(Name)
{
    std::cout << "FragTrap default constructor called" << std::endl;
   	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &other)
{
	_Name = other._Name;
	_HitPoints =other._HitPoints;
	_EnergyPoints = other._HitPoints;
	_AttackDamage = other._AttackDamage;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &other)
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
FragTrap::~FragTrap(void)
{
	//~ClapTrap();
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "FragTrap " << this->_Name;
		std::cout << " has not energy points to attack";
		return ;
	}
		
	std::cout << "FragTrap " << this->_Name;
	std::cout << " attacks " << target;
	std::cout << " causing " << "2 " << "points of damage!" <<std::endl;
	this->_EnergyPoints--;
	this->_HitPoints--;
	(void)_AttackDamage;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "ScavTrap " << this->_Name;
	std::cout << " is in Gatekeeper mode." << std::endl;
}
