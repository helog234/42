/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:47 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/26 09:23:23 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	_fill = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_fill = new T[n];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	_fill = new T[other.size()];
	for (size_t i = 0; i < other.size(); i++)
		_fill[i] = other._fill[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);
	delete [] _fill;
	size_t len = other.size();
	_fill = new T[len];
	for (size_t i = 0; i < len; i++)
		_fill[i] = other._fill[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t i)
{
	if (i > size())
		throw Array<T>::OutOfBound();
	return (_fill[i]);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _fill;
}

template <typename T>
size_t Array<T>::size() const
{
	size_t i = 0;
	while (_fill[i])
		i++;
	return (i);
}