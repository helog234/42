/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:13:51 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/29 13:00:45 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <exception>

class RPN
{
	public:
		RPN(std::string argv);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		void calculate();
		
		class Error: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Error";
			}
		};
	
	private:
		std::stack<int> _operants;
		std::string _argv;
		bool isOperant(char c);
		int add(int a, int b);
		int sub(int a, int b);
		int multi(int a, int b);
		int divid(int a, int b);
};

#endif