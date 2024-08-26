/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:13:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/26 13:57:56 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string argv)
:_argv(argv)
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
		_operants = other._operants;
	return (*this);
}

void RPN::calculate()
{
	size_t i = 0;
	int j;
	std::stack<int> tmp;

	while (_argv[i])
	{
		if (!isdigit(_argv[i]) && !isOperant(_argv[i]) && _argv[i] != ' ')
			throw Error();
		else if (isdigit(_argv[i]))
			_operants.push(static_cast<int>(_argv[i])  - '0');
		else if (isOperant(_argv[i]))
		{
			if (_operants.size() < 2)
				throw Error();
			j = _operants.top();
			_operants.pop();
			switch (_argv[i])
			{
				case '+': 
					j = add(_operants.top(), j); break;
				case '-': 
					j = sub(_operants.top(), j); break;
				case '*': 
					j = multi(_operants.top(), j); break;
				case '/': 
					j = divid(_operants.top(), j); break;
			} 
			_operants.pop();
			_operants.push(j);
		}	
		i++;
	}
	if (_operants.size() != 1)
		throw Error();
	std::cout << _operants.top() << std::endl;
}

bool RPN::isOperant(char c)
{
	if (c == '+' || c == '-')
		return (true);
	if (c == '*' || c == '/')
		return (true);
	return (false);	
}

int	RPN::add(int a, int b)
{
	return (a + b);
}

int	RPN::sub(int a, int b)
{
	return (a - b);
}

int	RPN::multi(int a, int b)
{
	return (a * b);
}

int	RPN::divid(int a, int b)
{
	if (b == 0)
		throw Error();
	return (a / b);
}

const char *RPN::Error::what() const throw()
{
	return "Error";
}