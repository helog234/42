/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:49:28 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/22 11:42:16 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> container(10);
	for (size_t i = 0; i < 10; i++)
		container[i] = i + 2;
	
	std::cout << "Values in container:" << std::endl;
	for (std::vector<int>::iterator it = container.begin(); \
	it != container.end(); ++it)
		std::cout << *it << " ";
	
	std::cout << std::endl;
	int to_find = 6;
	std::cout << "Value to find : ";
	std::cout << to_find << std::endl;
	try
	{
		easyfind(container, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	to_find = 1;
	std::cout << "Value to find : ";
	std::cout << to_find << std::endl;
	try
	{
		easyfind(container, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}