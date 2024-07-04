/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:02:57 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 18:47:03 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <map>

Harl::Harl( void ) 
{
	convert["DEBUG"] = D;
	convert["INFO"] = I;
	convert["WARNING"] = W;
	convert["ERROR"] = E;
}

Harl::~Harl ( void ) {}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout<< "I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years ";
	std::cout << "whereas you started working here since last month.";
	std::cout << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! " << std::endl;
	std::cout << "I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}

void Harl::complain( std::string level )
{
	std::map<std::string, Entry>::iterator it = convert.find(level);
	if (it != convert.end())
	{
		switch (it->second)
		{
			case D:
				debug();
			case I:
				info();
			case W:
				warning();
			case E:
				error();
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break;
		}
	}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		
}
