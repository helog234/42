#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

SpellBook::SpellBook(const SpellBook& other)
{
	(void)other;
}

SpellBook& SpellBook::operator=(const SpellBook& other)
{
	(void)other;
	return (*this);
}

void SpellBook::learnSpell(ASpell* spell)
{
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); \
	it != spellBook.end(); it++)
	{
		if (it->first == spell->getName())
			return;
	}
	spellBook[spell->getName()] = spell;
}

void SpellBook::forgetSpell(const std::string& spellName)
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

ASpell* SpellBook::createSpell(const std::string& spellName)
{
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); \
	it != spellBook.end(); it++)
	{
		if (it->first == spellName)
			return (it->second);
	}
	return (NULL);
}