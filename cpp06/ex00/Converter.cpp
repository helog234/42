/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:20:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/18 13:59:55 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

char toChar(const std::string& str)
{
	return (str[0]);
}

int	toInt(const std::string& str)
{
	return (atoi(str.c_str()));
}

float toFloat(const std::string& str)
{
	if (str == "-inff")
		return (-std::numeric_limits<float>::infinity());
	else if (str == "+inff")
		return (std::numeric_limits<float>::infinity());
	else if (str == "nanf")
		return std::numeric_limits<float>::quiet_NaN();
	else
		return (atof(str.c_str()));
}

double toDouble(const std::string& str)
{
	if (str == "-inff")
		return (-std::numeric_limits<double>::infinity());
	else if (str == "+inff")
		return (std::numeric_limits<double>::infinity());
	else if (str == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	else
		return (atof(str.c_str()));
}
