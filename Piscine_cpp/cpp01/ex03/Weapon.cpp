/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:50:19 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 16:48:25 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
: _type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
	return (_type);
}

void Weapon::	setType(const std::string& type)
{
	_type = type;
}
