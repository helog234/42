/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:20:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/14 16:41:11 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
:  ClapTrap("FragTrap", _initHit, _initEnergy, _initAttack) 
{
	 std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Name)
: ClapTrap(Name, _initHit, _initEnergy, _initAttack)
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
: ClapTrap(other)
{
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
		ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

void FragTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _Name;
	std::cout << " Request a high five !" << std::endl;
}
