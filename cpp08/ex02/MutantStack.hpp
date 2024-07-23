/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:59:20 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/23 11:18:58 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
		public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack &other){*this = other;}
		MutantStack& operator=(const MutantStack &other)
		{
			if (this == &other)
				return (*this);
			this->c = other.c;
			return (*this);
		}
		
		typedef typename std::stack<int>::container_type::iterator iterator;
		iterator begin() {return std::stack<T>::c.begin();}
		iterator end() {return std::stack<T>::c.end();}
};

#endif
