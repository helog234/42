/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:02:30 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/18 15:46:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Checker.hpp"
#include "Converter.hpp"
#include "Print.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int i = 1;
	while (argv[i])
	{
		ScalarConverter::convert(argv[i]);
		std::cout << "----" << std::endl;
		i++;
	}
	return (1);
}

/* int	main(void)
{
	std::string tests[] = {"a", "g", "10", "-10", "2147483647", "-2147483648",
	"0.0f", "-4.2f", "2147483647.44", "0.0", "-4.2", "-inff", 
	"+inff", "nanf", "-inf", "+inf", "nan"};
	int num_tests = sizeof(tests) / sizeof(tests[0]);
	
	for (int i = 0; i < num_tests; ++i) 
	{
		ScalarConverter::convert(tests[i]);
		std::cout << "----" << std::endl;
	}
	
	return (0);
	
} */
