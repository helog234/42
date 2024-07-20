/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:48:37 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/18 12:59:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HPP	
# define CHECKER_HPP
# include <iostream>
# include <limits>
# include "ScalarConverter.hpp"

bool	isChar(const std::string& str, size_t len);
bool	isInt(const std::string& str, size_t len);
bool	isFloat(const std::string& str, size_t len);
bool	isDouble(const std::string& str, size_t len);
bool	isMath(const std::string& str);
bool	checkLimits(size_t num, int type, char sign);

#endif