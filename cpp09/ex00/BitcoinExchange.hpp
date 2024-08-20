/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:55:46 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 11:19:07 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <math.h>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream &dataCSV);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		const BitcoinExchange &operator=(const BitcoinExchange &other) const;
		
		void ctrBtc(std::ifstream &dataRef);
		void printBtc(std::string first, std::string date, double amont, double rate);
		bool checkConditions(std::string first);

		class FileError: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Error opening file.";
			}
		};
		
	private:
		std::ifstream _dateRef;
		std::map<std::string, double> _toCheck;
};

bool isFloat(const std::string& str, size_t len);
bool checkLimits(size_t num, int type, char sign);

enum	type
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	MATH = 4,
};

#endif