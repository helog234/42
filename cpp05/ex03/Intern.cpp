/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:39:11 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/24 14:43:29 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	_convert[0] = "presidential pardon";
	_convert[1] = "robotomy request";
	_convert[2] = "shrubbery creation";
}

Intern::Intern(const Intern &other)
{
	(void)other;
}
Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int	i = 0;
	while (i < 3)
	{
		if (_convert[i] == name)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			throw WrongName();

	}	
}

