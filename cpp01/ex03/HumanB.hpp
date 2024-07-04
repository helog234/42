/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:17:38 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 16:53:16 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		const std::string _name;
		Weapon	*_weapon;
	public:
		HumanB(const std::string& name);
		HumanB(const std::string& name, Weapon* weapon);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon& type);
		std::string getName() const;
};

#endif