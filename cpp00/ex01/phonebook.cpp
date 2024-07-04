/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:08:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 15:31:38 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"
#include <stdlib.h>
#include <iomanip>

Phonebook::Phonebook(void) : _index(1) {}

Phonebook::~Phonebook(void) {}

void Phonebook::addContact()
{
	if (this->_index > 7)
	{
		std::cout << "\033[38;5;208mThis action will overwrite the data from the contact ";
		std::cout << _Contacts[0].getFirstName() << " " << _Contacts[0].getLastName() << "\033[0m" << std::endl;
		std::string str = "";
		while (true)
		{
			std::cout << "Confirm your choice (y/n) :" << std::endl;
			std::cout << "> ";
			std::cin >> str;
			if (str == "n")
				return ;
			if (str == "y")
				break ;
		}
		for (int i = 1; i < 8; i++)
		{
			_Contacts[i - 1] = _Contacts[i];
		}
		_index = 7;
	}
	std::cout << "Add a new contact" << std::endl;
	_Contacts[_index].setFirstName();
	_Contacts[_index].setLastName();
	_Contacts[_index].setNickname();
	_Contacts[_index].setPhoneNumber();
	_Contacts[_index].setDarkestSecret();
	_index++;
}

void Phonebook::printList(const std::string& str) const
{
	std::cout << "|";
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::left << std::setw(10) << str;
}

void Phonebook::printContact(int index) const
{
	if (_Contacts[index].getFirstName() == "")
		std::cout << "\033[1;31mWrong index. No entry for this index.\033[0m" << std::endl;
	else
	{
		std::cout << std::endl;
		std::cout << "********" << std::endl;
		std::cout << _Contacts[index].getFirstName() << std::endl;
		std::cout << _Contacts[index].getLastName() << std::endl;
		std::cout << _Contacts[index].getNickname() << std::endl;
		std::cout << _Contacts[index].getPhoneNumber() << std::endl;
		std::cout << _Contacts[index].getDarkestSecret() << std::endl;
		std::cout << "********" << std::endl;
		std::cout << std::endl;
	}
}

void Phonebook::searchContact() const
{
	for (int i = 1; i < 8; i++)
	{
		std::cout << std::right << std::setw(9) << i;
		printList(_Contacts[i].getFirstName());
		printList(_Contacts[i].getLastName());
		printList(_Contacts[i].getNickname());
		std::cout << std::endl;
	}
	while (true)
	{
		std:: string str;
		int	index;
		std::cout << "Select a contact by its index number" << std::endl;
		std::cout << "> ";
		std::cin >> str;
		if (str.length() > 1 || !isdigit(str[0]))
			std::cout << "\033[1;31mWrong format. Index is between 1 and 8\033[0m" << std::endl;
		else
		{
			index = std::atoi(str.c_str());
			if (index >= 0 && index <= 8)
			{
				printContact(index);
				break ;
			}
			else
				std::cout << "\033[1;31mWrong format. Index is between 1 and 8\033[0m" << std::endl;
		}
	}
}
