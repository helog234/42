/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_vec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:09:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/19 17:08:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::vecSortPairs(std::vector<int> &ref, int half, int end)
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

std::vector<int>::iterator PmergeMe::vecBinarySearch(std::vector<int> &ref, int elem)
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

void PmergeMe::vecMergeInsert(std::vector<int> &largers, std::vector<int> &smallers)
{
	std::vector<int>::iterator it = smallers.begin();
	while (it != smallers.end())
	{
		int elem = *it;
		std::vector<int>::iterator pos = vecBinarySearch(largers, elem);
		largers.insert(pos, elem);
		it = smallers.erase(it);
	}
}
 

std::vector<int> PmergeMe::vecSort(std::vector<int> &ref)
{
	if (ref.size() <= 1)
		return (ref);
		
	int half = ref.size() / 2;
	vecSortPairs(ref, half, ref.size());
	std::vector<int> smallers = vecInsert(0, half, ref);
	std::vector<int> largers = vecInsert(half, ref.size(), ref);
	largers = vecSort(largers);
	vecMergeInsert(largers, smallers);
	return (largers);
}


std::vector<int> PmergeMe::getVecResult()
{
	return (_vec);
}