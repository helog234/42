/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:02:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 11:34:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &dataCSV)
{
	std::string Line;
	
	_dateRef.open("DateRef.csv");
	if (!_dateRef)
		throw FileError();
	getline(dataCSV, Line);
	while (getline(dataCSV, Line))
	{
		std::string date = Line.substr(0, 10);
		std::string tmp = Line.substr(11, Line.length());
		double rate = atof(tmp.c_str());
		_toCheck[date] = rate;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	if (_dateRef.is_open())
		_dateRef.close();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

const BitcoinExchange& BitcoinExchange::\
operator=(const BitcoinExchange &other) const
{
	(void)other;
	return (*this);
}

bool BitcoinExchange::checkConditions(std::string first)
{
	std::string date;
	std::string tmp;
	
	_dateRef.clear();
	_dateRef.seekg(0, std::ios::beg);
	if (first.length() < 12)
	{
		std::cout << "Error: bad input => ";
		std::cout << first << std::endl;
		return (false);
	}
	date = first.substr(0, 10);
	if (!_dateRef)
	{
		std::cerr << "File stream is not open or in a bad state.\n";
		return false;
	}
	while (getline(_dateRef, tmp))
	{
		if (tmp == date)
			break;
	}
	if (_dateRef.eof() && tmp != date)
	{
		std::cout << "Error: bad date => ";
		std::cout << date << std::endl;
		return (false);
	}
	tmp = first.substr(12, first.length());
	double value = atof(tmp.c_str());
	if (value < 0.0 || value > 1000.0)
	{
		if (value < 0.0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::ctrBtc(std::ifstream &testFile)
{
	std::string search;
	double tmp = 0.0;
	std::string tmpstr;
	std::map<std::string, double>::iterator it;

	getline(testFile, search);
	while (getline(testFile, search))
	{
		if (checkConditions(search))
		{
			for (it = _toCheck.begin(); it != _toCheck.end(); ++it)
			{
				std::string searchDate = search.substr(0, 10);
				if (it->first >= searchDate)
				{
					if (searchDate == it->first)
						tmpstr = search.substr(11, search.length());
					else
					{
						if (it != _toCheck.begin())
							it--;
						else
							break;
					}
					std::string amount = search.substr(12, search.length());
					tmp = atof(amount.c_str());
					printBtc(search, searchDate, tmp, it->second);
					break;
				}
			}
			tmpstr = search.substr(11, search.length());
		}
	}
}

void BitcoinExchange::printBtc(std::string first, \
std::string date, double amount, double rate)
{
	std::cout << date << " =>";
	if (!isFloat(first.substr(12, first.length()), first.length()))
		std::cout << first.substr(12, first.length());
	else
		std::cout << amount;
	/* std::cout << "amount " << amount << std::endl;
	std::cout << "rate " << std::fixed << std::setprecision(2) << rate << std::endl; */
	std::cout << " = " << std::fixed << std::setprecision(2);
	std::cout << amount * rate << std::endl;
}

bool checkLimits(size_t num, int type, char sign)
{
	if (type == INT)
	{
		if (sign == '-' && static_cast<int>(num) < std::numeric_limits<int>::min())
			return (false);
		if ((isdigit(sign) || sign == '+') && \
		static_cast<int>(num) > std::numeric_limits<int>::max())
			return (false);
	}
	else if (type == FLOAT)
	{
		if (sign == '-' && static_cast<float>(num) < std::numeric_limits<float>::min())
			return (false);
		if ((isdigit(sign) || sign == '+') && \
		static_cast<float>(num) > std::numeric_limits<float>::max())
			return (false);
	}
	else if (type == DOUBLE)
	{
		if (sign == '-' && static_cast<double>(num) < std::numeric_limits<double>::min())
			return (false);
		if ((isdigit(sign) || sign == '+') && \
		static_cast<double>(num) > std::numeric_limits<double>::max())
			return (false);
	}
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
		if (checkLimits(num, FLOAT, str[0]) == false)
			return (false);
	}
	return (false);
}