/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:55:33 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/25 10:48:54 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <map>

Harl::Harl( void ) {}

Harl::~Harl ( void ) {}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout<< " I really do!";
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger!";
	std::cout << "If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years ";
	std::cout << "whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain( std::string level )
{
	std::map<std::string, void (Harl::*)(void)> levelMap;
	
	levelMap["DEBUG"] = &Harl::debug;
	levelMap["INFO"] = &Harl::info;
	levelMap["WARNING"] = &Harl::warning;
	levelMap["ERROR"] = &Harl::error;
	
	std::map<std::string, void (Harl::*)(void)>::iterator it = levelMap.find(level);
	if (it != levelMap.end())
		(this->*(it->second))();
	else
		std::cout << "Type of complain not found" << std::endl;
}
