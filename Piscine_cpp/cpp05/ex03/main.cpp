/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:10:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/27 09:05:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include "Intern.hpp"


int	main(void)
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* rrf2 = someRandomIntern.makeForm("shrubbery creation", "Nice");
		AForm* rrf3 = someRandomIntern.makeForm("presidential pardon", "Cool");
		//AForm* rrf4 = someRandomIntern.makeForm("try", "Nope");
		Bureaucrat bureaucrat1("Alice", 5);
		Bureaucrat bureaucrat2("Bob", 40);
		Bureaucrat bureaucrat3("Georges", 148);

		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
		std::cout << *rrf1 << std::endl;
		std::cout << *rrf2 << std::endl;
		std::cout << *rrf3 << std::endl;
		//std::cout << *rrf4 << std::endl;
		
		bureaucrat1.signForm(*rrf1);
		bureaucrat2.signForm(*rrf2);
		bureaucrat1.signForm(*rrf3);
		bureaucrat2.signForm(*rrf1); 
		
		bureaucrat1.executeForm(*rrf3);
		bureaucrat2.executeForm(*rrf3);
		bureaucrat2.executeForm(*rrf1);
		bureaucrat3.executeForm(*rrf2);
		
		//post modifications
		std::cout << *rrf1 << std::endl;
		std::cout << *rrf1 << std::endl;
		std::cout << *rrf2 << std::endl;
		std::cout << *rrf3 << std::endl;
		delete rrf1;
		delete rrf2;
		delete rrf3;
		//std::cout << *rrf4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}