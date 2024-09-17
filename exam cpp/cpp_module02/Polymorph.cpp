#include "Polymorph.hpp"

Polymorph::Polymorph()
: ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph()
{}
Polymorph::Polymorph(const Polymorph& other)
: ASpell("Polymorph", "turned into a critter")
{
	(void)other;
}

Polymorph& Polymorph::operator=(const Polymorph& other)
{
	(void)other;
	return (*this);
}

Polymorph* Polymorph::clone() const
{
	return (new Polymorph(*this));
}