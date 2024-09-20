/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:21:09 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/18 13:40:25 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP	
# define CONVERTER_HPP
# include <iostream>
# include <limits>
# include <cmath>
# include "Checker.hpp"

char toChar(const std::string& str);
int	toInt(const std::string& str);
float toFloat(const std::string& str);
double toDouble(const std::string& str);

#endif