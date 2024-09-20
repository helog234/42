/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:57:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 16:53:09 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		const std::string _name;
		const Weapon& _weapon;
	public:
		HumanA(const std::string& name, const Weapon& weapon);
		~HumanA();
		void attack() const;
		std::string getName() const;
};

#endif
