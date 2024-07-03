/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:49:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 12:53:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name)
:_name(name)
{
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	//std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &other)
: _name(other._name)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (other._inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = other._inventory[i]->clone();
		}
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
		if (other._inventory[i] != nullptr)
		{
			delete _inventory[i];
			_inventory[i] = other._inventory[i]->clone();
		}
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
	int	i = 0;
	while (_used[i])
	{
		delete _used[i];
		i++;
	}
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
	int i;

	i = 0;
	while (_used[i])
	{
		if (_used[i] == nullptr)
		{
			//std::cout << "Character unequip methode called" << std::endl;
			_used[i] = _inventory[idx];
			_inventory[idx] = nullptr;
			return ;
		}
		i++;
	}
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
