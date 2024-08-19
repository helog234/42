/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:39:34 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/19 13:58:23 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	try
	{
		PmergeMe merge = PmergeMe(argv);
		merge.sorting();
		std::vector<int> res = merge.getResult();
		//int	end = merge.getSize();
		for (std::vector<int>::iterator it = res.begin(); \
		it != res.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		if (std::is_sorted(res.begin(), res.end()))
			std::cout << "Is sorted "<< std::endl;
		else
			std::cout << "Is not sorted "<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return (0);
}