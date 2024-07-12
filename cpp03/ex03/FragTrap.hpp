/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:12:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/12 17:36:14 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{

	public:
		FragTrap(void);
		FragTrap(std::string Name);
		FragTrap(const FragTrap& other);
		FragTrap &operator=(const FragTrap& other);
		virtual ~FragTrap();
		void attack(const std::string& target);
		void highFivesGuys(void);

	/* protected:
		const std::string	_Name;
		int					_HitPoints;
		int					_EnergyPoints;
		int					_AttackDamage; */
};

#endif