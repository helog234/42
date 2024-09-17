#include "ATarget.hpp"

ATarget::ATarget(const std::string& Type)
: type(Type) {}

ATarget::~ATarget() {}

ATarget::ATarget(const ATarget& other)
: type(other.type) {}

ATarget& ATarget::operator=(const ATarget& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

const std::string& ATarget::getType()
{
	return (type);
}


void ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << type << " has been ";
	std::cout << spell.getEffect() << std::endl;
}

