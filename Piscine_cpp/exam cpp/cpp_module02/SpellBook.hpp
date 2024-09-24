#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP
# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell*> book;
		SpellBook(const SpellBook& other);
		SpellBook& operator=(const SpellBook& other);

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		ASpell* createSpell(const std::string& spellName);
};

#endif