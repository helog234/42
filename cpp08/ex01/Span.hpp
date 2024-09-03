/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:50:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/09/02 09:09:31 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <limits>
# include <algorithm>

class Span
{
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		void addNumber(const int i);
		void addNumber(std::vector<int>::iterator \
		start, std::vector<int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		class AlreadyTaken: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class RangeTooShort: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class RangeTooBig: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		
	private:
		unsigned int p_N;
		std::vector<int> p_size;
};

#endif