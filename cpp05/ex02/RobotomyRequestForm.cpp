/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:40:23 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 17:27:26 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
: AForm(target, 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getState() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << "rizzz RIIIIZZZZ rizzz blop bip" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << "Robotomy on "  << _target << " completed!" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " have failed" << std::endl;
}