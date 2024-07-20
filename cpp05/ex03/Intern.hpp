/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:32:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/16 16:21:50 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include <map>

class AForm;

class Intern
{		
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		
		AForm* makeForm(std::string name, std::string target);
		enum FormType {P, R, S};
		
		std::map<std::string, FormType> convert;
		class WrongName: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Intern : No form corresponding to this name.";
				}
		};
		
	private:
		/* void _StockForm(AForm* toAdd);
		struct FormNode
		{
			AForm* form;
			FormNode* next;
		};
		FormNode* _List;
		void _RemoveList(); */
		
		
		
		
};


#endif