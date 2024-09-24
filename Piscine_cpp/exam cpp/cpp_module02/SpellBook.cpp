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
	for (std::map<std::string, ASpell*>::iterator it = book.begin();\
	it != book.end(); it++)
	{
		if (it->second == spell)
			return ;
	}
	book[spell->getName()] = spell;
}

void SpellBook::forgetSpell(std::string spellName)
{
	for (std::map<std::string, ASpell*>::iterator it = book.begin();\
	it != book.end(); it++)
	{
		if (it->first == spellName)
		{
			book.erase(it);
			return ;
		}
	}
}

ASpell* SpellBook::createSpell(const std::string& spellName)
{
	for (std::map<std::string, ASpell*>::iterator it = book.begin();\
	it != book.end(); it++)
	{
		if (it->first == spellName)
		{
			return (it->second);
		}
	}
	return (NULL);
}