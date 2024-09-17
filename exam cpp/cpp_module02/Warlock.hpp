#pragma once
#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <vector>

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::vector<ASpell*> spells;
		Warlock(const Warlock& other);
		Warlock& operator=(const Warlock& other);

	public:
		Warlock(std::string const &Name, std::string const &Title);
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void setTitle(const std::string& Title);

		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		void launchSpell(const std::string spellName, const ATarget& target);
};

#endif