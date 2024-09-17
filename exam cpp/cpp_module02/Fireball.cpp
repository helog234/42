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
	(void)other;
	return (*this);
}

Fireball* Fireball::clone() const
{
	return (new Fireball(*this));
}