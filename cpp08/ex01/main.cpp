/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:28:23 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/23 08:43:22 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	// main de l'exercie
	/* Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0; */

	//test avec 10000
	Span sp = Span(10000);
	try
	{
		std::vector<int> range;
		for (size_t i = 0; i < 10000; i++)
			range.push_back(i);
		
		sp.addNumber(range.begin(), range.end());
		
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	//test avec range trop grand
	try
	{
		std::vector<int> range;
		for (size_t i = 0; i < 300; i++)
			range.push_back(i);
		
		sp.addNumber(range.begin(), range.end());
		
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		for (size_t i = 0; i < 300; i++)
			range.push_back(i);
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Span sp1 = Span(5);
	try
	{
		sp1.addNumber(1);
		sp1.addNumber(2);
		sp1.addNumber(3);
		sp1.addNumber(1);
		sp1.addNumber(1);
		sp1.addNumber(1);
		
		std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//test avec range trop petit
	Span sp2 = Span(5);
	try
	{
		sp2.addNumber(42);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

// shortest span ne peut pas etre 0 si incrementation un par un car pas meme valeur