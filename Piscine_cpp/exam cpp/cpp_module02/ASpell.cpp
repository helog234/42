#include "ASpell.hpp"

ASpell::ASpell(const std::string& Name, const std::string& Effect)
: name(Name), effect(Effect) {}

ASpell::~ASpell()
{}

ASpell::ASpell(const ASpell& other)
{
	name = other.name;
	effect = other.effect;
}

ASpell& ASpell::operator=(const ASpell& other)
{
	if (this != &other)
	{
		name = other.name;
		effect = other.effect;
	}
	return (*this);
}

const std::string& ASpell::getName() const
{
	return (name);
}

const std::string& ASpell::getEffect() const
{
	return (effect);
}

void ASpell::launch(const ATarget& target)
{
	target.getHitBySpell(*this);
}
