/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/09 10:32:45 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string const target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		
		void execute(Bureaucrat const & executor) const;
		void beSigned(Bureaucrat &ref);
		
		class ErrorFileException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "could not open file";
				}
		};
		
	private:
	std::string const	_target;
	//bool				_signed;
	//int 				_signedGrade;
	//int 				_execGrade;
};

#endif