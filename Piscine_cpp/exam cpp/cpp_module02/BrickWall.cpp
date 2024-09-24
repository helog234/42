#include "BrickWall.hpp"

BrickWall::BrickWall()
: ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall()
{}

BrickWall::BrickWall(const BrickWall& other)
: ATarget("Inconspicuous Red-brick Wall")
{
	(void)other;
}

BrickWall& BrickWall::operator=(const BrickWall& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

const std::string& BrickWall::getType() const
{
	return (type);
}

BrickWall* BrickWall::clone() const
{
	return (new BrickWall(*this));
}