/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:01:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/08 10:32:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

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

	void signForm(Form &ref);
	
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade is too high!";
			}
	};
	
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade is too low!";
			}
	};
	
	void incrementGrade();
	void decrementGrade();
	
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref);


#endif