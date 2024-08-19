/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:27:49 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/19 17:07:46 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **str)
{
	parsing(str);
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_lst = other._lst;
	}
	return (*this);
}

void PmergeMe::parsing(char **str)
{
	int len = 0;
	
	while (str[len])
		len++;
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; str[i][j]; j++)
		{
			if (!isdigit(str[i][j]))
				throw WrongEntry();
		}
		_vec.push_back(atoi(str[i]));
		_lst.push_back(atoi(str[i]));
	}
}

void PmergeMe::sorting()
{
	std::cout << "Before (vector): " << RED;
	for (std::vector<int>::iterator it \
	 = _vec.begin(); it != _vec.end(); ++it)
	{
			std::cout << *it << " ";
	}
	std::cout << std::endl;
	clock_t t1;
	t1 = clock();
	_vec = vecSort(_vec);
	t1 = clock() - t1;
	std::cout << INFO << "After (vector): " << GREEN;
	for (std::vector<int>::iterator it \
	 = _vec.begin(); it != _vec.end(); ++it)
	{
			std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Before (lst): " << RED;
	for (std::list<int>::iterator it \
	 = _lst.begin(); it != _lst.end(); ++it)
	{
			std::cout << *it << " ";
	}
	std::cout << std::endl;
	clock_t t2;
	t2 = clock();
	_lst = lstSort(_lst);
	t2 = clock() - t2;
	std::cout << INFO << "After (vector): " << GREEN;
	for (std::list<int>::iterator it \
	 = _lst.begin(); it != _lst.end(); ++it)
	{
			std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << INFO << "Time to process a range of ";
	std::cout << _vec.size() << "  elements with std::vector : " << YELLOW;
	std::cout << static_cast<float>(t1)/CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	std::cout << INFO << "Time to process a range of ";
	std::cout << _lst.size() << "  elements with std::list : " << YELLOW;
	std::cout << static_cast<float>(t2)/CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	std::cout << INFO;
}

