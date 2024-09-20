/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:56:28 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 13:34:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "Fixed.hpp"
# pragma once

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float i, const float j);
		Point(const Point &t);
		Point&	operator=(const Point& t);
		Fixed	getFixedX(void) const;
		Fixed	getFixedY(void) const;
		float	getFloatX(void) const;
		float	getFloatY(void) const;
		~Point();
};

#endif