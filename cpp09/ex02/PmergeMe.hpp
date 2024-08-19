/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:27:41 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/19 13:54:42 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERGEME_HPP
# define PERGEME_HPP
# include <iostream>
# include <deque>
# include <list>
# include <exception>
# include <utility>

class PmergeMe
{
	public:
		PmergeMe(char **str);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void sorting();
		std::vector<int> getResult();
		//int PmergeMe::getSize();

		class WrongEntry: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Wrong entry. Only unique and positiv interger must be passed.";
			}
		};
		
		
	private:
		//std::deque<unsigned int> _originList;
		//std::deque<std::pair<int, std::pair<int, bool> > > _originList;
		std::vector<int> _vec;
		//std::vector<int> _vecRes;
		std::list<int> _lst;
		//std::list<int> _lstRes;
		/* std::deque<int> _dq;
		std::deque<int> _dqResult; */
		/* std::list<int> &_lst;
		std::list<int> &_lstResult; */
		
		void parsing(char **str);
		
		void vecSortInPair(std::vector<int> &ref, int half, int end);
		std::vector<int> vecSortLarger(std::vector<int> &ref);
		std::vector<int>::iterator binarySearch(std::vector<int> &ref, int elem);
		void mergeInsert(std::vector<int> &largers, std::vector<int> &smallers);
		std::vector<int> vecInsert(int start, int end, std::vector<int> &ref);
		//void sortPairs(std::deque<std::pair<int, std::pair<int, bool> > >::iterator it);
		//void pushInLst(std::deque<std::pair<int, std::pair<int, bool> > >::iterator it);
};

#endif