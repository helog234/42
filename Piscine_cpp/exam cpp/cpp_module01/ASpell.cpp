#include "ASpell.hpp"

ASpell::ASpell(const std::string& Name, const std::string& Effect)
: name(Name), effects(Effect) {}

ASpell::~ASpell()
{}

ASpell::ASpell(const ASpell& other)
{
	name = other.name;
	effects = other.effects;
}

ASpell& ASpell::operator=(const ASpell& other)
{
	if (this != &other)
	{
		name = other.name;
		effects = other.effects;
	}
	return (*this);
}

const std::string& ASpell::getName() const
{
	return (name);
}

const std::string& ASpell::getEffects() const
{
	return (effects);
}

void ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}
