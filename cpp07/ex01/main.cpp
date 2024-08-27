/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:03:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/27 16:09:28 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	// Test with integer array
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, intLength, printValue);
	std::cout << std::endl;

	// Test with string array
	std::string stringArray[] = {"Hello", "world", "!"};
	std::size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);
	iter(stringArray, stringLength, printValue);
	std::cout << std::endl;

	// Test with double array
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
	iter(doubleArray, doubleLength, printValue);
	std::cout << std::endl;

	// Test with float array
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::size_t floatLength = sizeof(floatArray) / sizeof(floatArray[0]);
	iter(floatArray, floatLength, printValue);
	std::cout << std::endl;

	// Test with char array
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::size_t charLength = sizeof(charArray) / sizeof(charArray[0]);
	iter(charArray, charLength, printValue);
	std::cout << std::endl;

	return 0;
}