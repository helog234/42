#ifndef FIREBALL_HPP
# define FIREBALL_HPP
# include <iostream>
# include "ASpell.hpp"

class Fireball: public ASpell
{
	private:


	public:
		Fireball();
		~Fireball();
		Fireball(const Fireball& other);
		Fireball& operator=(const Fireball& other);

		Fireball* clone() const;

};

#endif