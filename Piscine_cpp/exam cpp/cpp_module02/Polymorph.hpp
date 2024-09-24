#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP
# include <iostream>
# include "ASpell.hpp"

class Polymorph: public ASpell
{
	public:
		Polymorph();
		~Polymorph();
		Polymorph(const Polymorph& other);
		Polymorph& operator=(const Polymorph& other);

		const std::string& getName() const;
		const std::string& getEffects() const;

		Polymorph* clone() const;
};

#endif