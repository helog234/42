/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:17:38 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/25 10:43:11 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
# pragma once
# include <iostream>
# include "HumanA.hpp"
# include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
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