/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:32:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 17:44:17 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

class intern
{
	private:
		
	public:
		intern(void);
		intern(const intern &other);
		intern &operator=(const intern &other);
		~intern();
		
		AForm* makeForm(std::string name, std::string target);
	
};


#endif