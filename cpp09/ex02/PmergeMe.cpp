/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:27:49 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/19 13:59:31 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **str)
{
	parsing(str);
	int flag = 0;
	for (std::vector<int>::iterator it \
	 = _vec.begin(); it != _vec.end(); ++it)
	{
		if (flag == 0)
		{
			std::cout << "(";
			std::cout << *it << ", ";
			flag = 1;
		}
		else
		{
			std::cout << *it << ") ";
			flag = 0;
		}
	}
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
	_vec = vecSortLarger(_vec);
	//insert
}

 void PmergeMe::vecSortInPair(std::vector<int> &ref, int half, int end)
 {
	for (int i = 0; i < half; i++)
	{
		if (half + i < end && ref[i] > ref[half + i])
		{
			int temp = ref[i];
			ref[i] = ref[half + i];
			ref[half + i] = temp;
		}
	}
 }

 std::vector<int> PmergeMe::vecInsert(int start, int end, std::vector<int> &ref)
 {
	std::vector<int> newVec;
	for (int i = start; i < end; i++)
	{
		newVec.push_back(ref[i]);
	}
	return (newVec);
 }

std::vector<int>::iterator PmergeMe::binarySearch(std::vector<int> &ref, int elem)
{
	int low = 0;
	int high = ref.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (ref[mid] == elem)
			throw WrongEntry();
		if (ref[mid] < elem)
			low = mid + 1;
		else
			high = mid;
	}

	return (ref.begin() + low);
}

 void PmergeMe::mergeInsert(std::vector<int> &largers, std::vector<int> &smallers)
 {
	std::vector<int>::iterator it = smallers.begin();
	while (it != smallers.end())
	{
		int elem = *it;
		std::vector<int>::iterator pos = binarySearch(largers, elem);
		largers.insert(pos, elem);
		it = smallers.erase(it);
	}
 }
 

 std::vector<int> PmergeMe::vecSortLarger(std::vector<int> &ref)
 {
	if (ref.size() <= 1)
		return (ref);
		
	int half = ref.size() / 2;
	vecSortInPair(ref, half, ref.size());
	for (std::vector<int>::iterator it = ref.begin(); \
	it != ref.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::vector<int> smallers = vecInsert(0, half, ref);
	std::vector<int> largers = vecInsert(half, ref.size(), ref);
	largers = vecSortLarger(largers);
	/* std::cout << "before adding smallers" << std::endl;
	for (std::vector<int>::iterator it = largers.begin(); \
	it != largers.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	for (std::vector<int>::iterator it = smallers.begin(); \
	it != smallers.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl; */
	mergeInsert(largers, smallers);
	return (largers);
}


std::vector<int> PmergeMe::getResult()
{
	return (_vec);
}

