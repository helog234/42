/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:47:26 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 17:35:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		Character(std::string const & name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria *_inventory[4];
		struct MateriaNode
		{
			AMateria* materia;
			MateriaNode* next;
		};
		MateriaNode* _unequipped;
		void addUnequipped(AMateria* m);
		void clearUnequipped();
};

#endif