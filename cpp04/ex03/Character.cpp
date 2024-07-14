/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:49:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/14 17:17:07 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name)
:_name(name)
{
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	_unequipped = nullptr;
	//std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &other)
: _name(other._name)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	_unequipped = nullptr;
	MateriaNode* current = other._unequipped;
	while (current != nullptr)
	{
		addUnequipped(current->materia->clone());
		current = current->next;
	}
	//std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	clearUnequipped();

	MateriaNode* current = other._unequipped;
	while (current != nullptr)
	{
		addUnequipped(current->materia->clone());
		current = current->next;
	}
	//std::cout << "Character assignment operator called" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i] != nullptr)
			delete _inventory[i];
	}
	clearUnequipped();
	//std::cout << "Character destructor called" << std::endl;
}
std::string const& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	//std::cout << "Character equip called" << std::endl;
	while (i < 4)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			return ;
		}
		i++;
	}
	
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	addUnequipped(_inventory[idx]);
	_inventory[idx] = nullptr;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && _inventory[idx])
	{
		_inventory[idx]->AMateria::use(target);
		unequip(idx);
	}
	//std::cout << "Character use methode called" << std::endl;	
}

void Character::clearUnequipped()
{
	MateriaNode* current = _unequipped;
	while (current != nullptr)
	{
		MateriaNode* next = current->next;
		delete current->materia;
		delete current;
		current = next;
	}
	_unequipped = nullptr;
	//std::cout << "All unequipped Materias deleted" << std::endl;
}

void Character::addUnequipped(AMateria* m)
{
	if (!_unequipped)
	{
		MateriaNode* newNode = new MateriaNode();
		newNode->materia = m;
		newNode->next = nullptr;
		_unequipped = newNode;
	}
	else
	{
		MateriaNode* current = _unequipped;
		while (current && current->next)
			current = current->next;
		MateriaNode* newNode = new MateriaNode();
		newNode->materia = m;
		newNode->next = nullptr;
		current->next = newNode;
	}
}
