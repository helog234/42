/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:50:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/23 08:22:22 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <limits>

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
				virtual const char* what() const throw()
				{
					return "Location already filled";
				}
		};
		class RangeTooShort: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Range smaller or equal to 1 cannot be calculate";
				}
		};
		class RangeTooBig: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Range is too big to fit into determined sized";
				}
		};
		
		
	private:
		unsigned int p_N;
		std::vector<int> p_size;
};

#endif