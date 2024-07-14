/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:08:46 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/12 18:20:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
    public:
		ClapTrap(std::string Name);
        ClapTrap(const ClapTrap& other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void displayInfo(void) const;

	protected:
		ClapTrap(std::string Name, int hit, int energy, int attack);
		const std::string	_Name;
		int					_HitPoints;
		int					_EnergyPoints;
		int					_AttackDamage;

		static const unsigned int	_initHit = 10;
		static const unsigned int	_initEnergy = 10;
		static const unsigned int	_initAttack = 0;
		
};
#endif

