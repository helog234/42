#include "Fireball.hpp"

Fireball::Fireball()
: ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball()
{}

Fireball::Fireball(const Fireball& other)
: ASpell("Fireball", "burnt to a crisp")
{
	(void)other;
}

Fireball& Fireball::operator=(const Fireball& other)
{
	if (this != &other)
	{
		name = other.name;
		effects = other.effects;
	}
	return (*this);
}

const std::string& Fireball::getName() const
{
	return (name);
}

const std::string& Fireball::getEffects() const
{
	return (effects);
}

Fireball* Fireball::clone() const
{
	return (new Fireball(*this));
}
