#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

TargetGenerator::TargetGenerator(const TargetGenerator& other)
{
	(void)other;
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& other)
{
	(void)other;
	return (*this);
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	for (std::map<std::string, ATarget*>::iterator it = book.begin(); \
	it != book.end(); it++)
	{
		if (it->first == target->getType())
			return;
	}
	book[target->getType()] = target;
}
void TargetGenerator::forgetTargetType(const std::string& type)
{
	for (std::map<std::string, ATarget*>::iterator it = book.begin(); \
	it != book.end(); it++)
	{
		if (it->first == type)
		{
			book.erase(it);
			return;
		}
	}
}

ATarget* TargetGenerator::createTarget(const std::string& type)
{
	for (std::map<std::string, ATarget*>::iterator it = book.begin(); \
	it != book.end(); it++)
	{
		if (it->first == type)
			return (it->second);
	}
	return (NULL);
}