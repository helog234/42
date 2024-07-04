/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:32:04 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 15:04:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> 
#include "contact.hpp"

Contact::Contact() : _FirstName(""), _LastName(""), _Nickname(""), _PhoneNumber(""), _DarkestSecret("") {}

Contact::Contact(const std::string& FirstName, const std::string& LastName, const std::string& Nickname,const std::string&PhoneNumber, const std::string& DarkestSecret)
: _FirstName(FirstName), _LastName(LastName), _Nickname(Nickname), _PhoneNumber(PhoneNumber), _DarkestSecret(DarkestSecret) {}

Contact::~Contact(void) {}

std::string Contact::getFirstName(void) const
{
	return this->_FirstName;
}

std::string Contact::getLastName(void) const
{
	return this->_LastName;
}

std::string Contact::getNickname(void) const
{
	return this->_Nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_PhoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return this->_DarkestSecret;
}

void	Contact::setFirstName(void)
{
	while (true)
	{
		std::cout << "Set first name: ";
		std::cin >> this->_FirstName;
		if (!this->_FirstName.empty())
			break;
	}
	return ;
}

void Contact::setLastName(void)
{
	while (true)
	{
		std::cout << "Set last name: ";
		std::cin >> this->_LastName;
		if (!this->_LastName.empty())
			break;
	}
	return ;
}

void Contact::setNickname(void)
{
	while (true)
	{
		std::cout << "Set nickname: ";
		std::cin >> this->_Nickname;
		if (!this->_Nickname.empty())
			break;
	}
	return ;
}

void Contact::setPhoneNumber(void)
{	
	while (true)
	{
		std::cout << "Set phonenumber: ";
		std::cin >> this->_PhoneNumber;
		if (!ctrDigits(this->_PhoneNumber))
			std::cout << "\033[1;31mNondigit entry. Only digits and \"+\" are accepted.\033[0m" << std::endl;
		else
			break;
	}
	return ;
}

void Contact::setDarkestSecret(void)
{
	while (true)
	{
		std::cout << "Set darkest secret: ";
		std::cin >> this->_DarkestSecret;
		if (!this->_DarkestSecret.empty())
			break;
	}
	return ;
}

int	Contact::ctrDigits(std::string str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((i == 0 && str[i] == '+'))
			i++ ;
		else if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
