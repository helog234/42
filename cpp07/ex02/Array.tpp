/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:47 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/20 15:29:17 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::Array()
:_fill(NULL)
{}

Array::Array(unsigned int n)
:_fill(new n)
{}

Array(const Array &other)
{
	if (this != &other)
	{
		while (other._f)
		{
			/* code */
		}
		
		
	}
}

Array::~Array()
{
}