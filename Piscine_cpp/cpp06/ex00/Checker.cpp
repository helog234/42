/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:10:35 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/26 13:42:18 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.hpp"

bool isChar(const std::string& str, size_t len)
{
	if (len == 1 && !isdigit(str[0]))
		return true;
	return false;
}

bool isInt(const std::string& str, size_t len)
{
	int	sign = 0;
	int	j;
	size_t	num = 0;
	if (str[0] == '-' || str[0] == '+')
		sign = 1;
	if (sign == 1 && len > 11)
		return (false);
	for (size_t i = sign; i < len; i++)
	{
		if (!isdigit(str[i]))
			return (false);
		j = str[i] - '0';
		num = num * 10 + j;
	}
	if (checkLimits(num, INT, str[0]) == false)
			return (false);
	return (true);
}

bool isFloat(const std::string& str, size_t len)
{
	int	sign = 0;
	int	j;
	int num = 0;
	
	if (str[0] == '-' || str[0] == '+')
		sign = 1;
	for (size_t i = sign; i < len; i++)
	{
		if (((sign == 1 && i > 1) || (sign == 0 && i > 0)) \
		&& !isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.' && isdigit(str[i + 1]) && str[i + 2] == 'f')
			return (true);
		j = str[i] - '0';
		num = num * 10 + j;
	}
	if (checkLimits(num, FLOAT, str[0]) == false)
			return (false);
	return (false);
}

bool isDouble(const std::string& str, size_t len)
{
	int	sign = 0;
	int	j;
	int num = 0;

	if (str[0] == '-' || str[0] == '+')
		sign = 1;
	for (size_t i = sign; i < len; i++)
	{
		if (((sign == 1 && i > 1) || (sign == 0 && i > 0)) \
		&& !isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.' && isdigit(str[i + 1]))
			return (true);
		j = str[i] - '0';
		num = num * 10 + j;
	}
	if (checkLimits(num, DOUBLE, str[0]) == false)
			return (false);
	return (false);
}

bool isMath(const std::string& str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	else if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	return (false);
}

bool checkLimits(size_t num, int type, char sign)
{
	if (type == INT)
	{
		if (sign == '-' && static_cast<int>(num) < std::numeric_limits<int>::min())
			return (false);
		if ((isdigit(sign) || sign == '+') && \
		num > static_cast<size_t> (std::numeric_limits<int>::max()))
			return (false);
	}
	else if (type == FLOAT)
	{
		if (sign == '-' && static_cast<float>(num) < std::numeric_limits<float>::min())
			return (false);
		if ((isdigit(sign) || sign == '+') && \
		num > static_cast<size_t> (std::numeric_limits<float>::max()))
			return (false);
	}
	else if (type == DOUBLE)
	{
		if (sign == '-' && static_cast<double>(num) < std::numeric_limits<double>::min())
			return (false);
		if ((isdigit(sign) || sign == '+') && \
		(num) > static_cast<size_t> (std::numeric_limits<double>::max()))
			return (false);
	}
	return (true);
}