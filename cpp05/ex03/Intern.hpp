/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:32:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/24 14:43:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

class Intern
{		
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		
		AForm* makeForm(std::string name, std::string target);
		std::string _convert[3];
		
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