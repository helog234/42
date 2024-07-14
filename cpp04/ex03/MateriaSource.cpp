/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:04:03 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/14 17:24:47 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
	for (size_t i = 0; i < 4; i++)
		_stock[i] = nullptr;
	//std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (other._stock[i])
			_stock[i] = other._stock[i]->clone();
		else
			_stock[i] = nullptr;
	}
	//std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		//std::cout << "BON MateriaSource assignment operator called" << std::endl;
		for (size_t i = 0; i < 4; i++)
		{
			if (_stock[i])
				delete _stock[i];
			if (other._stock[i])
			{
				_stock[i] = other._stock[i]->clone();
			}
			else
				_stock[i] = nullptr;
		}
	}
	//std::cout << "MateriaSource assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() 
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_stock[i])
			delete _stock[i];
	}
	//std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (_stock[i] == nullptr)
		{
			_stock[i] = m->clone();
			delete m;
			return ;
		}
		i++;
	}
	delete m;
	//std::cout << "learnMateria called" << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i;

	i = 0;
	//std::cout << "createMateria called" << type << std::endl;
	while (_stock[i])
	{
		if (_stock[i]->getType() == type)
			return (_stock[i]->clone());
		i++;
	}
	return (0);
}