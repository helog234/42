/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:39:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/14 16:39:31 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string Name)
: ClapTrap(Name + "_clap_name", FragTrap::_initHit, ScavTrap::_initEnergy, FragTrap::_initAttack), _Name(Name)
{

    std::cout << "DiamondTrap default constructor called" << std::endl;
	
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
:ClapTrap(other.ClapTrap::_Name), ScavTrap(other._Name), FragTrap(other._Name), _Name(other._Name)
{
	_HitPoints =other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	return *this;
}
// Destructor
DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
    return ;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->_Name << " ";
	std::cout << "ClapTrap name: " <<this->ClapTrap::_Name << std::endl;
    return ;
}

void DiamondTrap::guardGate()
{
	ScavTrap::guardGate();
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::highFivesGuys(void)
{
	FragTrap::highFivesGuys();
}

void DiamondTrap::displayInfo(void)
{
	
	std::cout << _Name << " has ";
	std::cout << _HitPoints << " hit points left ";
	std::cout << _EnergyPoints << " Energy points left ";
	std::cout << _AttackDamage << " Attack damage left" << std::endl;
}