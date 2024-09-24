#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
: ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh()
{}

Fwoosh::Fwoosh(const Fwoosh& other)
: ASpell("Fwoosh", "fwooshed")
{
	(void)other;
}

Fwoosh& Fwoosh::operator=(const Fwoosh& other)
{
	if (this != &other)
	{
		name = other.name;
		effects = other.effects;
	}
	return (*this);
}

const std::string& Fwoosh::getName() const
{
	return (name);
}

const std::string& Fwoosh::getEffects() const
{
	return (effects);
}

Fwoosh* Fwoosh::clone() const
{
	return (new Fwoosh(*this));
}

