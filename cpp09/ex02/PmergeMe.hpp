/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:27:41 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/19 17:02:29 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERGEME_HPP
# define PERGEME_HPP
# include <iostream>
# include <deque>
# include <list>
# include <exception>
# include <utility>
# include <time.h>
# define RED  "\e[0;31m"
# define GREEN  "\e[0;32m"
# define INFO "\033[0m"
# define YELLOW  "\e[0;33m"

class PmergeMe
{
	public:
		PmergeMe(char **str);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void sorting();
		std::vector<int> getVecResult();
		std::list<int> getLstResult();

		class WrongEntry: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Wrong entry. Only unique and positiv interger must be passed.";
			}
		};
		
		
	private:
		std::vector<int> _vec;
		std::list<int> _lst;

		void parsing(char **str);
		
		void vecSortPairs(std::vector<int> &ref, int half, int end);
		std::vector<int> vecSort(std::vector<int> &ref);
		std::vector<int>::iterator vecBinarySearch(std::vector<int> &ref, int elem);
		void vecMergeInsert(std::vector<int> &largers, std::vector<int> &smallers);
		std::vector<int> vecInsert(int start, int end, std::vector<int> &ref);

		void lstSortPairs(std::list<int> &smallers, std::list<int> &largers);
		std::list<int> lstSort(std::list<int> &ref);
		std::list<int>::iterator lstBinarySearch(std::list<int> &ref, int elem);
		void lstMergeInsert(std::list<int> &largers, std::list<int> &smallers);
		void lstInsert(int half, std::list<int> &smallers, std::list<int> &largers, std::list<int> &ref);

};

#endif