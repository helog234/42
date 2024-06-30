/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:39:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/30 14:25:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void)
: ClapTrap()
{
    std::cout << " DiamondTrap default constructor called" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string Name)
: ClapTrap(Name + "_clap_name")
{
	_Name = Name;
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	_Name = other._Name;
	_HitPoints =other._HitPoints;
	_EnergyPoints = other._HitPoints;
	_AttackDamage = other._AttackDamage;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
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
DiamondTrap::~DiamondTrap(void)
{
	//~ClapTrap();
    std::cout << "DiamondTrap destructor called" << std::endl;
    return ;
}

void DiamondTrap::whoAmI()
{
	std::cout << this->_Name << this->ClapTrap::_Name << std::endl;
    return ;
}

void DiamondTrap::guardGate()
{
	ScavTrap::guardGate();
}

void DiamondTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void DiamondTrap::highFivesGuys(void)
{
	FragTrap::highFivesGuys();
}