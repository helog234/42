#include "Warlock.hpp"

Warlock::Warlock(const std::string& Name, const std::string& Title)
: name(Name), title(Title)
{
	std::cout << name << ": ";
	std::cout << "This looks like another boring day.";
	std::cout << std::endl;
}
Warlock::~Warlock()
{
	std::cout << name << ": ";
	std::cout << "My job here is done!";
	std::cout << std::endl;
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

void Warlock::introduce() const
{
	std::cout << name << ": ";
	std::cout << "I am " << name << ", ";
	std::cout << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); \
	it != spellBook.end(); it++)
	{
		if (it->first == spell->getName())
			return;
	}
	spellBook[spell->getName()] = spell;
}
/* void Warlock::forgetSpell(const std::string& spellName)
{
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); \
	it != spellBook.end(); it++)
	{
		if (it->first == spellName)
		{
			spellBook.erase(it);
			return;
		}
	}
} */

void Warlock::forgetSpell(std::string spellName)
{
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); \
	it != spellBook.end(); it++)
	{
		if (it->first == spellName)
		{
			spellBook.erase(it);
			return;
		}
	}
}

void Warlock::launchSpell(std::string spellName, const ATarget& target)
{
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); \
	it != spellBook.end(); it++)
	{
		if (it->first == spellName)
		{
			it->second->launch(target);
			return;
		}
	}
}