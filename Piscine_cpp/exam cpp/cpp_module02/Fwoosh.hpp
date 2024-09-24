#ifndef FWOOSH_HPP
# define FWOOSH_HPP
# include <iostream>
# include "ASpell.hpp"

class Fwoosh: public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		Fwoosh(const Fwoosh& other);
		Fwoosh& operator=(const Fwoosh& other);

		const std::string& getName() const;
		const std::string& getEffects() const;

		Fwoosh* clone() const;
};

#endif