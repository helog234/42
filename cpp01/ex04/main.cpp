/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:29:48 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 18:04:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	errorManagment(std::ifstream &file, std::ofstream &newFile)
{
	if (!file.is_open())
	{
		std::cout << "Could not open the file." << std::endl;
		return (1);
	}
	if (!newFile.is_open())
	{
		std::cout << "Could not create or open new file." << std::endl;
		file.close();
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 4)
		return (0);

	std::string filename = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	std::string line;
	std::size_t	found = 0;
	std::ifstream file(filename);
	std::ofstream newFile(filename + ".replace");

	if (errorManagment(file, newFile) != 0)
		return (1);
	
	while (getline(file, line))
	{
		found = line.find(str1);
		while (found != std::string::npos)
		{
			line.erase(found, str1.length());
			line.insert(found, str2);
			found = line.find(str1, found + str2.length());
		}
		newFile << line << std::endl;
	}
	file.close();
	newFile.close();
	return (0);
}

//The std::string::find function search for a substring
//It returns the position of the first character of the first match of the substring if found. 
//If the substring is not found, it returns std::string::npos. 
//The second parameter of the find function specifies the position in the string to start the search