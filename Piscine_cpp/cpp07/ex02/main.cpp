/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:35:38 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/21 12:22:58 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> a(3);
	Array<int> b = a;

	for (size_t i = 0; i < 3; i++)
	{
		a[i] = i + 2;
		b[i] = i + 1;
	}
	for (size_t i = 0; i < 3; i++)
		std::cout << "a :" << a[i] << " b : " << b[i] << std::endl;
	
	int * c = new int();
	std::cout << "c : " << *c << std::endl;
	
	Array<int> d(2);
	try
	{
		for (size_t i = 0; i < 3; i++)
			std::cout << "c : " << d[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}