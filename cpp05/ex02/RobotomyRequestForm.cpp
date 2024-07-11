/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:40:23 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/09 10:43:17 by hgandar          ###   ########.fr       */
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

/* void RobotomyRequestForm::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > _signedGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw AlreadySignedException();
	else
		_signed = true;
	AForm::beSigned(ref);
} */

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getState() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << "rizzz RIIIIZZZZ rizzz blop bip" << std::endl;
	std::srand(std::time(nullptr));
	double successProbability = 0.5;
	if (static_cast<double>(std::rand()) / RAND_MAX < successProbability)
		std::cout << "Robotomy on "  << _target << " completed!" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " have failed" << std::endl;
}