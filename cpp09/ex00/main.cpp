/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:05:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 11:23:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <ctime>
#include "BitcoinExchange.hpp"

bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// The Daylight Saving Time flag (tm_isdst) is greater than zero 
//if Daylight Saving Time is in effect, 
//zero if Daylight Saving Time is not in effect, 
//and less than zero if the information is not available.
void	createCSV(std::ofstream &outfile)
{
	struct tm datetime;
	time_t timestamp;
	char FormatDate[11];
	
	datetime.tm_sec = 0;
	datetime.tm_min = 0;
	datetime.tm_hour = 0;
	datetime.tm_mday = 1;
	datetime.tm_mon = 0;
	datetime.tm_year = 0;
	datetime.tm_wday = 0;
	datetime.tm_yday = 0;
	datetime.tm_isdst = -1;
	for (size_t year = 2009; year < 2025; year++)
	{
		datetime.tm_year = year - 1900;
		for (size_t month = 0; month < 12; month++)
		{
			datetime.tm_mon = month;
			for (size_t day = 1; day <= 31; day++)
			{
				if ((month == 1 && day > (isLeapYear(year) ? 29 : 28)) || \
				((month == 3 || month == 5 || month == 8 || month == 10) && day > 30) \
				|| day > 31)
					continue;
				datetime.tm_mday = day;
				timestamp = mktime(&datetime);
				 if (timestamp != -1)
				 	strftime(FormatDate, sizeof(FormatDate), "%Y-%m-%d", &datetime);
				outfile << FormatDate << "\n";
			}
		}
	}

}

void generateInfos(std::ifstream &dataCSV, std::ifstream &testFile)
{
	try
	{
		BitcoinExchange btc = BitcoinExchange(dataCSV);
		btc.ctrBtc(testFile);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(int argc, char **argv)
{
	std::ofstream DateRef;
	std::ifstream testFile;
	std::ifstream dataCSV;

	if (argc < 2)
	{
		return(std::cerr << "Error: could not open file." << std::endl, 1);
		return (1);
	}
	dataCSV.open("data.csv");
	testFile.open(argv[1]);
	DateRef.open("DateRef.csv");
	createCSV(DateRef);
	if (!DateRef || !dataCSV || !testFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		if (DateRef.is_open())
			DateRef.close();
		if (testFile.is_open())
			testFile.close();
		if (dataCSV.is_open())
			dataCSV.close();
		return (1);
	}
	DateRef.close();
	generateInfos(dataCSV, testFile);
	dataCSV.close();
	testFile.close();
	return (0);
}