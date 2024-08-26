/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:20:46 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/26 13:44:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](size_t i);
		size_t size() const;

		class OutOfBound: public std::exception
		{
			public:
				virtual const char* what() const throw();	
		};
	private:
		T *_fill;
};

# include "Array.tpp"

#endif