/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:55:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 16:10:44 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}


Brain::Brain(const Brain& other)
{
	(void)other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain& other)
{
	(void)other;
	return (*this);
	std::cout << "Brain assignment operator called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}