/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:59:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/26 13:53:18 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
: p_N(N)
{
	p_size.reserve(N);
}

Span::~Span()
{

}

Span::Span(const Span &other)
{
	p_N = other.p_N;
	p_size.reserve(p_N);
	for (std::vector<int>::iterator it = p_size.begin(); \
	it != p_size.end(); ++it)
		p_size.at(*it) = other.p_size.at(*it);
}
Span& Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	p_N = other.p_N;
	p_size.reserve(p_N);
	for (std::vector<int>::iterator it = p_size.begin(); \
	it != p_size.end(); ++it)
		p_size.at(*it) = other.p_size.at(*it);
	return (*this);
}
void Span::addNumber(const int i)
{
	if (p_size.size() >= p_N)
		throw AlreadyTaken();
	p_size.push_back(i);
}

void Span::addNumber(std::vector<int>::iterator start, \
std::vector<int>::iterator end)
{
	size_t range = std::distance(start, end);
	if (p_size.size() + range > p_N)
		throw RangeTooBig();
	p_size.insert(p_size.end(), start, end);
}

unsigned int Span::shortestSpan()
{
	if (p_size.size() < 2)
		throw RangeTooShort();

	std::vector<int> sorted = p_size;
	std::sort(sorted.begin(), sorted.end());
	
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

unsigned int Span::longestSpan()
{
	if (p_size.size() < 2)
		throw RangeTooShort();

	int minElement = *std::min_element(p_size.begin(), p_size.end());
	int maxElement = *std::max_element(p_size.begin(), p_size.end());
	
	return (maxElement - minElement);
}

const char *Span::AlreadyTaken::what() const throw()
{
	return "Location already filled";
}

const char *Span::RangeTooShort::what() const throw()
{
	return "Range smaller or equal to 1 cannot be calculate";
}

const char *Span::RangeTooBig::what() const throw()
{
	return "Range is too big to fit into determined sized";
}