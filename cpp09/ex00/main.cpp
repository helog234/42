/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:05:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/20 10:45:43 by hgandar          ###   ########.fr       */
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

void generateInfos(std::ifstream &dataCSV, std::ifstream &testFile, std::ifstream &dateRef)
{
	BitcoinExchange btc = BitcoinExchange(dataCSV, dateRef);
	btc.ctrBtc(testFile);
}

int	main(int argc, char **argv)
{
	std::ofstream DateRef;
	std::ifstream testFile;
	std::ifstream dataCSV;
	std::ifstream dateRef;

	if (argc < 2)
	{
		return(std::cerr << "Error: could not open file." << std::endl, 1);
		return (1);
	}
	dataCSV.open("data.csv");
	createCSV(DateRef);
	if (!DateRef || !dataCSV)
	{
		std::cerr << "Error: could not open file." << std::endl;
		if (DateRef.is_open())
			DateRef.close();
		if (dataCSV.is_open())
			dataCSV.close();
		return (1);
	}
	DateRef.close();
	dateRef.open("DateRef.csv");
	testFile.open(argv[1]);
	if (!testFile || !dateRef)
	{
		std::cerr << "Error: could not open file." << std::endl;
		if (testFile.is_open())
			testFile.close();
		if (dateRef.is_open())
			dateRef.close();
		if (dataCSV.is_open())
			dataCSV.close();
		return (1);
	}
	generateInfos(dataCSV, testFile, dateRef);
	
	dataCSV.close();
	testFile.close();
	return (0);
}