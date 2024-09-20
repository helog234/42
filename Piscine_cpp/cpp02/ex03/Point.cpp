/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:48:40 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 14:08:25 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#pragma once

Point::Point() 
: _x(0), _y(0) {}

Point::Point(const float i, const float j)
: _x(i), _y(j) {}

Point::Point(const Point& t)
: _x(this->_x), _y(this->_y) {}

Point&	Point::operator=(const Point& t)
{
	if (this == &t)
		return (*this);
	return (*this);
}

Point::~Point() {}

Fixed	Point::getFixedX(void) const
{
	return (this->_x);
}

Fixed	Point::getFixedY(void) const
{
	return (this->_y);
}

float	Point::getFloatX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getFloatY(void) const
{
	return (this->_y.toFloat());
}