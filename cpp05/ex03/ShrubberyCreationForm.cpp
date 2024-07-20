/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:04:25 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/16 17:06:57 by hgandar          ###   ########.fr       */
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
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename);
	if (!outfile.is_open())
		throw ErrorFileException();
	outfile << "             v .   ._, |_  .," << std::endl;
    outfile << "      `-._\\/  .  \\ /    |/_" << std::endl;
    outfile << "          \\  _\\, y | \\//" << std::endl;
    outfile << "   _\\_.___\\, \\/ -.\\||" << std::endl;
    outfile << "      `7-,--.`._||  / / ," << std::endl;
    outfile << "      /'     `-. `./ / |/_.'" << std::endl;
    outfile << "                |    |//" << std::endl;
    outfile << "                |_    /" << std::endl;
    outfile << "                |-   |" << std::endl;
    outfile << "                |   =|" << std::endl;
    outfile << "                |    |" << std::endl;
	outfile << "---------------/ ,  . \\--------._" << std::endl;

	outfile.close();
}
