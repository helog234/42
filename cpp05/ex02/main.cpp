/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:10:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 17:14:28 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>

// j'ai ajouté une exepction dans le cas ou le formulaire est deja signé
int	main(void)
{
	// tester initialisation avec mauvaises valeurs
	/* try
	{
		Form wrongForm("Blablabla", 1, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	} */
	// tester in/de-crementation :
	try
	{
		Bureaucrat bureaucrat1("Alice", 5);
		Bureaucrat bureaucrat2("Bob", 40);
		Bureaucrat bureaucrat3("Georges", 148);
		RobotomyRequestForm form1("home");
		ShrubberyCreationForm form2("garden");
		PresidentialPardonForm form3("Palace");

		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;
		
	
		bureaucrat1.signForm(form1);
		bureaucrat2.signForm(form2);
		bureaucrat1.signForm(form3);
		bureaucrat2.signForm(form1);

		
		bureaucrat1.executeForm(form3);
		bureaucrat2.executeForm(form3);
		bureaucrat2.executeForm(form1);
		bureaucrat3.executeForm(form2);
		

		//post modifications
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}