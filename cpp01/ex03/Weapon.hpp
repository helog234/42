/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:49 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/25 08:52:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
#pragma once
#include <iostream>

class Weapon
{
private:
	std::string _type;
	
public:
	Weapon(const std::string& type);
	~Weapon();
	
	const std::string& getType() const;
	void	setType(const std::string& type);
};

#endif
