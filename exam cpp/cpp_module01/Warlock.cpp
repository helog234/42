#include "Warlock.hpp"

Warlock::Warlock(std::string const &Name, std::string const &Title)
: name(Name), title(Title) 
{
	book = new SpellBook;
	std::cout << name;
	std::cout << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	delete book;
	std::cout << name;
	std::cout << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& other)
: name(other.name), title(other.title) {}
 
Warlock& Warlock::operator=(const Warlock& other)
{
	if (this != &other)
	{
		name = other.name;
		title = other.title;
	}
	return (*this);
}

const std::string& Warlock::getTitle() const
{
	return (title);
}

const std::string& Warlock::getName() const
{
	return (name);
}

void Warlock::setTitle(const std::string& Title)
{
	title = Title;
}
void Warlock::introduce() const
{
	std::cout << name;
	std::cout << ": I am " << name;
	std::cout << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	book->learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
	book->forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
	ASpell* tmp = book->createSpell(spellName);
	if (tmp != NULL)
		tmp->launch(target);
}