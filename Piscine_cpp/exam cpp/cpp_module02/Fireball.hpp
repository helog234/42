#ifndef FIREBALL_HPP
# define FIREBALL_HPP
# include <iostream>
# include "ASpell.hpp"

class Fireball: public ASpell
{
	public:
		Fireball();
		~Fireball();
		Fireball(const Fireball& other);
		Fireball& operator=(const Fireball& other);

		const std::string& getName() const;
		const std::string& getEffects() const;

		Fireball* clone() const;
};

#endif