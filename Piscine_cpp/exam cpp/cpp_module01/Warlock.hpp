#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell*> spellBook;
		Warlock(const Warlock& other);
		Warlock& operator=(const Warlock& other);

	public:
		Warlock(const std::string& Name, const std::string& Title);
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void setTitle(const std::string& Title);
		void introduce() const;

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, const ATarget& target);
};

#endif