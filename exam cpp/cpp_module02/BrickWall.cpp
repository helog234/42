#include "BrickWall.hpp"

BrickWall::BrickWall()
: ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

BrickWall::BrickWall(const BrickWall& other)
: ATarget("Inconspicuous Red-brick Wall")
{
	(void)other;
}

BrickWall& BrickWall::operator=(const BrickWall& other)
{
	(void)other;
	return (*this);
}

BrickWall* BrickWall::clone() const
{
	return (new BrickWall(*this));
}
