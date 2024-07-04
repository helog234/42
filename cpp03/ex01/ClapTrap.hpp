/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:08:46 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 15:18:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		void displayInfo(void);

	protected:
		const std::string	_Name;
		int					_HitPoints;
		int					_EnergyPoints;
		int					_AttackDamage;
};

#endif

