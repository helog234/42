#include "Warlock.hpp"

Warlock::Warlock(const std::string& Name, const std::string& Title)
: name(Name), title(Title)
{
	std::cout << name << ": This looks like another boring day.";
	std::cout << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!";
	std::cout << std::endl;
}

Warlock::Warlock(const Warlock& other)
{
	name = other.name;
	title = other.title;
}

Warlock& Warlock::operator=(const Warlock& other)
{
	if (this != &other)
	{
		name = other.name;
		title = other.title;
	}
	return (*this);
}

const std::string& Warlock::getName() const
{
	return (name);
}

const std::string& Warlock::getTitle() const
{
	return (title);
}

void Warlock::setTitle(const std::string& Title)
{
	title = Title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", ";
	std::cout << title << "!" << std::endl;
}