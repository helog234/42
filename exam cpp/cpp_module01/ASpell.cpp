#include "ASpell.hpp"

ASpell::ASpell(const std::string& Name, const std::string& Effects)
: name(Name), effects(Effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(const ASpell& other)
: name(other.name), effects(other.effects) {}

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

const std::string& ASpell::getEffect() const
{
	return (effects);
}

void ASpell::launch(const ATarget& target)
{
	target.getHitBySpell(*this);
}
