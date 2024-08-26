/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:10:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 15:08:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>

// j'ai ajouté une exception dans le cas ou le formulaire est deja signé
int	main(void)
{
	// tester initialisation avec mauvaises valeurs
	/* try
	{
		Form wrongForm("Blablabla", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	} */
	// tester in/de-crementation :
	try
	{
		Bureaucrat bureaucrat1("Alice", 5);
		Bureaucrat bureaucrat2("Bob", 50);
		Form form1("Really important", 1, 1);
		Form form2("important", 5, 1);

		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		
	
		bureaucrat1.signForm(form1);
		bureaucrat1.signForm(form2);
		bureaucrat2.signForm(form2);
		bureaucrat1.signForm(form2);

		//post modifications
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}