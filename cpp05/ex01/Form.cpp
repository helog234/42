/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:58:32 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/08 11:45:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const name, int signedGrade, int execGrade)
: _name(name), _signed(false)
{
	if (signedGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signedGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	_signedGrade = signedGrade;
	_execGrade = execGrade;
}

Form::~Form()
{}

Form::Form(const Form &other)
: _name(other._name), _signed(other._signed), \
_signedGrade(other._signedGrade), _execGrade(other._execGrade)
{}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
		_signedGrade = other._signedGrade;
		_execGrade = other._execGrade;
	}
	return (*this);
}

std::string const Form::getName() const
{
	return (_name);
}

bool Form::getState() const
{
	return (_signed);
}

int Form::getSignedGrade() const
{
	return (_signedGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > _signedGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw AlreadySignedException();
	else
		_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& ref)
{
	out << ref.getName() << " form, signed status : " << ref.getState();
	out << ", grade required to sign it :" << ref.getSignedGrade();
	out << ", grade required to execute it: " << ref.getExecGrade();
	return (out);
}