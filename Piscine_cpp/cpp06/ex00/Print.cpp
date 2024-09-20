/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:58:38 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 16:48:34 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Print.hpp"

void printChar(char c)
{
	if (isprint(c))
	{
		std::cout << "'" << c << "'" << std::endl;
		std::cout << "Int : " << static_cast<int>(c) << std::endl;
		std::cout << "Float : ";
		std::cout << std::fixed << std::setprecision(1);
		std::cout <<  static_cast<float>(c) << 'f' << std::endl;
		std::cout << "Double : ";
		std::cout << std::fixed << std::setprecision(1);
		std::cout << static_cast<double>(c) << std::endl;
	}
	else
		std::cout << "Not printable" << c << std::endl;
}

void printInt(int i)
{
	std::cout << "Char : ";
	if (i < 0 || i > 127)
		std::cout << "Non displayable" << std::endl;
	else
	{
		if (!isprint(i))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	}
		
	std::cout << "Int : " << i << std::endl;
	std::cout << "Float : ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "Double : ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<double>(i) << std::endl;

}

void printFloat(float f)
{
	std::cout << "Char : ";
	if (static_cast<char>(f) < 0 || static_cast<char>(f) > 127)
		std::cout << "Non displayable" << std::endl;
	else
	{
		if (!isprint(f))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	}
	std::cout << "Int : ";
	if (static_cast<long>(f) > std::numeric_limits<int>::max() ||
	static_cast<long>(f) < std::numeric_limits<int>::min())
		std::cout << "Overflow" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "Float : ";
	std::cout << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
	std::cout << "Double : ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<double>(f) << std::endl;
}

void printDouble(double f)
{
	std::cout << "Char : ";
	if (static_cast<char>(f) < 0 || static_cast<char>(f) > 127)
		std::cout << "Non displayable" << std::endl;
	else
	{
		if (!isprint(f))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	}
	std::cout << "Int : ";
	if (static_cast<long>(f) > std::numeric_limits<int>::max() \
	|| static_cast<long>(f) < std::numeric_limits<int>::min())
		std::cout << "Overflow" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	//gives the smallest positive value representable by a float
	//but i want the min in the range so i do -max
	std::cout << "Float : ";
	if (f > std::numeric_limits<float>::max() \
	|| f < -std::numeric_limits<float>::max()) 
		std::cout << "Overflow" << std::endl;
	else
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(1) << static_cast<float>(f) << 'f' << std::endl;
	}
	std::cout << "Double : ";
	std::cout << std::fixed << std::setprecision(1) << f << std::endl;
}

void printMath(const std::string& str)
{
	std::cout << "Char: impossible" << std::endl; 
	std::cout << "Int: Overflow" << std::endl;
	if (str == "nan" || str == "nanf")
	{
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "Float: +inff" << std::endl;
		std::cout << "Double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "Float: -inff" << std::endl;
		std::cout << "Double: -inf" << std::endl;
	}
}

