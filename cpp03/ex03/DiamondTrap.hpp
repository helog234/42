/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:38:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/12 15:17:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{

	public:
		DiamondTrap(void);
		DiamondTrap(std::string Name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap &operator=(const DiamondTrap& other);
		~DiamondTrap();
		void whoAmI();
		void guardGate();
		void attack(const std::string& target);
		void highFivesGuys(void);
		void displayInfo(void);
		
		
	private:
			const std::string	_Name;
			int					_HitPoints;
			int					_EnergyPoints;
			int					_AttackDamage;
		
};

#endif