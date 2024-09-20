/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Derived.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:16:00 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/19 13:43:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DERIVED_HPP
# define DERIVED_HPP
# include "Base.hpp"
# include <stdlib.h>
# include <time.h> 

class A: public Base
{
	public:
		A();
		~A();
		static const std::string& getType();
};

class B: public Base
{
	public:
		B();
		~B();
		static const std::string& getType();
};

class C: public Base
{
	public:
		C();
		~C();
		static const std::string& getType();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
#endif