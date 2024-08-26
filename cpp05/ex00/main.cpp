/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:10:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 14:58:54 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

int	main(void)
{
	// tester initialisation avec mauvaises valeurs
	try
	{
		Bureaucrat bureaucrat1("Alice", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bureaucrat1("Alice", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// tester in/de-crementation :
	try
	{
		Bureaucrat bureaucrat1("Alice", 4);
		Bureaucrat bureaucrat2("Bob", 50);

		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		
	
		bureaucrat1.incrementGrade();
		bureaucrat2.decrementGrade();

		//post modifications
		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bureaucrat1("Alice", 1);

		std::cout << bureaucrat1 << std::endl;
		
	
		bureaucrat1.incrementGrade();

		//post modifications
		std::cout << bureaucrat1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}