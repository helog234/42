/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:58:32 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/26 11:56:47 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const name, int signedGrade, int execGrade)
: _name(name), _signed(false)
{
	if (signedGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signedGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	_signedGrade = signedGrade;
	_execGrade = execGrade;
	//std::cout << "AForm default constructor" << std::endl;
}


AForm::~AForm()
{
	//std::cout << "AForm destuctor" << std::endl;
}

AForm::AForm(const AForm &other)
: _name(other._name), _signed(other._signed), \
_signedGrade(other._signedGrade), _execGrade(other._execGrade)
{}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed;
		_signedGrade = other._signedGrade;
		_execGrade = other._execGrade;
	}
	return (*this);
}

std::string const AForm::getName() const
{
	return (_name);
}

bool AForm::getState() const
{
	return (_signed);
}

int AForm::getSignedGrade() const
{
	return (_signedGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > _signedGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw AlreadySignedException();
	else
		_signed = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& ref)
{
	out << ref.getName() << " form, signed status : " << ref.getState();
	out << ", grade required to sign it : " << ref.getSignedGrade();
	out << ", grade required to execute it: " << ref.getExecGrade();
	return (out);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return " form already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
	return " form needs to be signed prior executing";
}

const char *AForm::ErrorFileException::what() const throw()
{
	return " could not open file";
}
