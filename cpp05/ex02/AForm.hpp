/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:58:43 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 15:35:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string const name, int signedGrade, int execGrade);
		~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		std::string const getName() const;
		bool getState() const;
		int getSignedGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat &ref);
		virtual void execute(Bureaucrat const & executor) const = 0;
		
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too high (form)!";
				}

		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return " grade is too low!";
				}

		};
		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return " form already signed";
				}

		};
		class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return " form needs to be signed prior executing";
				}

		};
		class ErrorFileException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return " could not open file";
				}
		};
		
	private:
		std::string const	_name;
		bool				_signed;
		int 				_signedGrade;
		int 				_execGrade;
		
};

std::ostream& operator<<(std::ostream& out, const AForm& ref);

#endif