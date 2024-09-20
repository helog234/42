/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:01:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/26 11:57:34 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int	_grade;
		
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string const getName() const;
		int getGrade() const;

		void signForm(AForm &ref);
		//void checkConditions(AForm const & form);
		void executeForm(AForm const & form);
	
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		
		void incrementGrade();
		void decrementGrade();
	
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref);


#endif