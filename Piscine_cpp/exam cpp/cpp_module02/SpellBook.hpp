#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP
# include "ASpell.hpp"
# include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell*> spellBook;
		SpellBook(const SpellBook& other);
		SpellBook& operator=(const SpellBook& other);
		
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell* spell);
		void forgetSpell(const std::string& spellName);
		ASpell* createSpell(const std::string& spellName);
};

#endif