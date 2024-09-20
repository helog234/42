/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:04:25 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/26 11:59:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
: AForm(target, 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getState() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open())
		throw ErrorFileException();
	file << "             v .   ._, |_  .," << std::endl;
    file << "      `-._\\/  .  \\ /    |/_" << std::endl;
    file << "          \\  _\\, y | \\//" << std::endl;
    file << "   _\\_.___\\, \\/ -.\\||" << std::endl;
    file << "      `7-,--.`._||  / / ," << std::endl;
    file << "      /'     `-. `./ / |/_.'" << std::endl;
    file << "                |    |//" << std::endl;
    file << "                |_    /" << std::endl;
    file << "                |-   |" << std::endl;
    file << "                |   =|" << std::endl;
    file << "                |    |" << std::endl;
	file << "---------------/ ,  . \\--------._" << std::endl;

	file.close();
}

const char *ShrubberyCreationForm::ErrorFileException::what() const throw()
{
	return "could not open file";
}
