/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:20:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/12 17:32:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name)
: ClapTrap(Name, 100, 100, 30)
{
    std::cout << "HERE FragTrap default constructor called" << std::endl;
	std::cout << "hitpoint" << _HitPoints << std::endl;
    std::cout << "energy" << _EnergyPoints << std::endl;
    std::cout << "attack" << _AttackDamage << std::endl;
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
