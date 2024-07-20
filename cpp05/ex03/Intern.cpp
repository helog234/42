/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:39:11 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/16 16:53:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	convert["presidential pardon"] = P;
	convert["robotomy request"] = R;
	convert["shrubbery creation"] = S;
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
	std::map<std::string, FormType>::iterator it = convert.find(name);
	if (it != convert.end())
	{
		std::cout << "Intern creates " << name << std::endl;
		switch (it->second)
		{
			case P:
			{
				return (new PresidentialPardonForm(target));
			}
			case R:
			{
				return (new RobotomyRequestForm(target));
			}
			case S:
			{
				return (new ShrubberyCreationForm(target));
			}
		}
	}
	else
		throw WrongName();
}

