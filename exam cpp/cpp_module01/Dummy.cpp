#include "Dummy.hpp"

Dummy::Dummy()
: ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

Dummy::Dummy(const Dummy& other)
: ATarget("Target Practice Dummy")
{
	(void)other;
}

Dummy& Dummy::operator=(const Dummy& other)
{
	(void)other;
	return (*this);
}

Dummy* Dummy::clone() const
{
	return (new Dummy(*this));
}