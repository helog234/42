/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:08:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/28 13:06:38 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string Name)
:_Name(Name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(10)
{
    std::cout << "Default constructor called" << std::endl;
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
    (void) other;
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_Name;
		std::cout << " has not energy points to attack";
		return ;
	}
		
	std::cout << "ClapTrap " << this->_Name;
	std::cout << " attacks " << target;
	std::cout << " causing " << "2 " << "points of damage!" <<std::endl;
	this->_EnergyPoints--;
	this->_HitPoints--;
}
	
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_Name;
	std::cout << " is attacked " << "costing ";
	std::cout << amount << " Attack damage" << std::endl;
	this->_AttackDamage -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_Name;
		std::cout << " has not energy points to repair";
		return ;
	}
	std::cout << "ClapTrap " << this->_Name;
	std::cout << " repairs itself " << "costing ";
	std::cout << " 1 Hit point" << std::endl;
	this->_EnergyPoints--;
	this->_HitPoints +=amount;
}
void ClapTrap::displayInfo(void)
{
	
	std::cout << this->_Name << " has ";
	std::cout << this->_HitPoints << " hit points left ";
	std::cout << this->_EnergyPoints << " Energy points left ";
	std::cout << this->_AttackDamage << " Attack damage left" << std::endl;
}
