/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:29:48 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/24 18:02:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string line, str1, str2, newLine;
	std::fstream file;
	std::size_t	found = 0;
	
	if (argc < 4)
		return (0);
	file.open(argv[1], std::ios::in | std::ios::out);
	str1 = argv[2];
	str2 = argv[3];
	
	if (!file.is_open())
		std::cout << "Could not open the file." << std::endl;
	while (getline(file, line))
	{
		found = line.find(argv[2]);
		while (found != std::string::npos)
		{
			line.erase(found, str1.length());
			line.insert(found, str2);
			found = line.find(str1, found + str2.length());
		}
		newLine += line + "\n";
	}
	file.close();
	file.open(argv[1], std::ios::out | std::ios::trunc);
    file << newLine;
    file.close();
	return (0);
}