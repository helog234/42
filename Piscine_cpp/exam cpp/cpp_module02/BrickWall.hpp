#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP
# include <iostream>
# include "ATarget.hpp"

class BrickWall: public ATarget
{
	public:
		BrickWall();
		~BrickWall();
		BrickWall(const BrickWall& other);
		BrickWall& operator=(const BrickWall& other);

		const std::string& getType() const;

		BrickWall* clone() const;
		
};

#endif