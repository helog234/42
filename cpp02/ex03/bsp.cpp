/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:29:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/28 09:03:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point&	getCenter(Point const a, Point const b, Point const c)
{
	static Point	center;
	float	x;
	float	y;
	x = (a.getFloatX() + b.getFloatX() + c.getFloatX()) / 3;
	y = (a.getFloatY() + b.getFloatY() + c.getFloatY()) / 3;
	center = Point(x, y);
	return (center);
}

Point	getIntersection(Point const i, Point const j, Point const center)
{
	if ((i.getFloatX() < center.getFloatX() && j.getFloatX() > center.getFloatX()) ||
	(i.getFloatX() > center.getFloatX() && j.getFloatX() < center.getFloatX())) 
	{
		float intersectY = i.getFloatY() + (j.getFloatY() - i.getFloatY()) * 
		(center.getFloatX() - i.getFloatX()) / (j.getFloatX() - i.getFloatX());
		return Point(center.getFloatX(), intersectY);
	}
		return (Point());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	center = getCenter(a, b, c);
	
	if (center.getFixedX() < point.getFixedX())
		

	
	

	
	
}