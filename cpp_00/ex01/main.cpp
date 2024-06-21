/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:12:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/20 13:35:17 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	Phonebook	repo;
	std::string str;
	
	std::cout << "*******************************" << std::endl;
	std::cout << "*";
	std::cout << " Welcome to your phonebook ! ";
	std::cout << "*" << std::endl;
	std::cout.width(29);
	std::cout << "*******************************" << std::endl;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "To add a contact type \"ADD\"." << std::endl;
		std::cout << "To search a contact type \"SEARCH\"." << std::endl;
		std::cout << "To exit the program type \"EXIT\". This will delete your contacts." << std::endl;
		std::cout << "> ";
		std::cin >> str;
		if (str == "EXIT")
			break ;
		if (str == "ADD")
			repo.addContact();
		else if (str == "SEARCH")
			repo.searchContact();
		else
		{
			std::cout << "\033[1;31mInput not recognize, try again.\033[0m" << std::endl;
			
		}
	}
	return (0);
}
