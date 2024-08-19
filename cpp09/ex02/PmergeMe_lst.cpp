/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_lst.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:10:29 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/19 17:08:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::list<int> PmergeMe::lstSort(std::list<int> &ref)
{
	if (ref.size() <= 1)
		return (ref);
		
	int half = ref.size() / 2;
	std::list<int> smallers, largers;
	lstInsert(half, smallers, largers, ref);
	lstSortPairs(smallers, largers);
	largers = lstSort(largers);
	lstMergeInsert(largers, smallers);
	return (largers);
}

void PmergeMe::lstInsert(int half, std::list<int> &smallers, std::list<int> &largers, std::list<int> &ref)
{
	int	i = 0;
	int end = ref.size();
	
	for (std::list<int>::iterator it = ref.begin(); i < end; it++)
	{
		if (i < half)
			smallers.push_back(*it);
		else
			largers.push_back(*it);
		i++;
	}
}

void PmergeMe::lstSortPairs(std::list<int> &smallers, std::list<int> &largers)
{
	std::list<int>::iterator it_l = largers.begin();
	
	for (std::list<int>::iterator it_s = smallers.begin(); it_s != smallers.end(); it_s++)
	{
		if (*it_s > *it_l)
		{
			int temp = *it_s;
			*it_s = *it_l;
			*it_l = temp;
		}
		it_l++;
	}
}

void PmergeMe::lstMergeInsert(std::list<int> &largers, std::list<int> &smallers)
{
	std::list<int>::iterator it = smallers.begin();
	while (it != smallers.end())
	{
		int elem = *it;
		std::list<int>::iterator pos = lstBinarySearch(largers, elem);
		largers.insert(pos, elem);
		it = smallers.erase(it);
	}
}

std::list<int>::iterator PmergeMe::lstBinarySearch(std::list<int> &ref, int elem)
{
	int low = 0;
	int high = ref.size();
	std::list<int>::iterator it = ref.begin();
	while (it != ref.end())
	{
		int mid = low + (high - low) / 2;
		if (*it == elem)
			throw WrongEntry();
		if (*it < elem)
			low = mid + 1;
		else
			return (it);
		it++;
	}
	return (it);
}

std::list<int> PmergeMe::getLstResult()
{
	return (_lst);
}