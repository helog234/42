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
	if (this != &other)
	{
		name = other.name;
		effects = other.effects;
	}
	return (*this);
}

const std::string& Polymorph::getName() const
{
	return (name);
}

const std::string& Polymorph::getEffects() const
{
	return (effects);
}

Polymorph* Polymorph::clone() const
{
	return (new Polymorph(*this));
}