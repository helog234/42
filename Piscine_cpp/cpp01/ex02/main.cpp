/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:37:39 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 16:47:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "address &str " << &str << std::endl;
	std::cout << "stringPTR " << stringPTR << std::endl;
	std::cout << "&stringREF " << &stringREF << std::endl;
	std::cout << "str " << str << std::endl;
	std::cout << "*stringPTR " << *stringPTR << std::endl;
	std::cout << "stringREF " << stringREF << std::endl;
	return (0);
}