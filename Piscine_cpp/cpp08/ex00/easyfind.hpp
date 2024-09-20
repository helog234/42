/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:49:50 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/22 11:42:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <iterator>
# include <algorithm>
# include <stdexcept>

template <typename T>
void easyfind(const T& iter, const int& num)
{
	typename T::const_iterator i = \
	std::find(iter.begin(), iter.end(), num);
	if (i == iter.end())
		throw std::runtime_error("Number not found in container");
	std::cout << "Found " << num << " at " << std::distance(iter.begin(), i) << std::endl;
}
#endif