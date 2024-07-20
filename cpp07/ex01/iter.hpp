/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:35:16 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/19 15:08:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include "iostream"

template <typename T>
void iter(T *add, size_t len, void (*func)(T &))
{
	for (size_t i = 0; i < len; i++)
		func(add[i]);
}
template <typename T>
void printValue(T &i)
{
	std::cout << i << std::endl;
}
#endif