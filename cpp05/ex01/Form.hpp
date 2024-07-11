/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:58:43 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/08 14:00:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(std::string const name, int signedGrade, int execGrade);
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		std::string const getName() const;
		bool getState() const;
		int getSignedGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat &ref);
		
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
					return "Grade is too low (form)!";
				}

		};
		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form already signed";
				}

		};
		
	private:
		std::string const	_name;
		bool				_signed;
		int 				_signedGrade;
		int 				_execGrade;
		
};

std::ostream& operator<<(std::ostream& out, const Form& ref);

#endif