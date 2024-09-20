/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:01:18 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 15:55:42 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Print.hpp"

void ScalarConverter::convert(const std::string& str)
{
	size_t len = str.length();
	
	if (len < 1)
		std::cout << "Not a valid input" << std::endl;
	else if (isChar(str, len))
		printChar(toChar(str));
	else if (isInt(str, len))
		printInt(toInt(str));
	else if (isFloat(str, len))
		printFloat(toFloat(str));
	else if (isDouble(str, len))
		printDouble(toDouble(str));
	else if (isMath(str) == true)
		printMath(str);
	else
	{
		std::cout << "*Not a valid input" << std::endl;
		std::cout << str << std::endl;
	}
		
}
ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}