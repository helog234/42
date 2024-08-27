/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:03:32 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/27 09:04:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::string const Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::signForm(AForm &ref)
{
	try
	{
		ref.beSigned(*this);
		std::cout << _name << " signed " << ref.getName() << std::endl;
	}
	catch(AForm::GradeTooLowException  &e)
	{
		std::cout << _name << " couldn't sign " << ref.getName();
		std::cout << " because " << e.what() << '\n';
	}
	catch(AForm::AlreadySignedException  &e)
	{
		std::cout << _name << " couldn't sign " << ref.getName();
		std::cout << " because " << e.what() << '\n';
	}
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (out);
}


void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed ";
		std::cout << form.getName() << std::endl;
	}
	catch(AForm::NotSignedException& e)
	{
		std::cout << _name << " could not execute " << form.getName();
		std::cout <<  " because " << e.what() << '\n';
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << _name << " could not execute " << form.getName();
		std::cout <<  " because " << e.what() << '\n';
	}
	catch(AForm::ErrorFileException& e)
	{
		std::cout << _name << " could not execute " << form.getName();
		std::cout <<  " because " << e.what() << '\n';
	}
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}