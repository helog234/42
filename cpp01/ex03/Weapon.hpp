/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:49 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 16:49:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP
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
