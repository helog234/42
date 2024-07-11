/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:42:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/09 10:36:46 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
: AForm(target, 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	return (*this);
}

/* void PresidentialPardonForm::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > _signedGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw AlreadySignedException();
	else
		_signed = true;
	AForm::beSigned(ref);
} */

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getState() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}