#include "Dummy.hpp"

Dummy::Dummy()
: ATarget("Target Practice Dummy") {}

Dummy::~Dummy()
{}

Dummy::Dummy(const Dummy& other)
: ATarget("Target Practice Dummy")
{
	(void)other;
}

Dummy& Dummy::operator=(const Dummy& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

const std::string& Dummy::getType() const
{
	return (type);
}

Dummy* Dummy::clone() const
{
	return (new Dummy(*this));
}
