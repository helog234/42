#pragma once
#ifndef FWOOSH_HPP
# define FWOOSH_HPP
# include <iostream>
# include "ASpell.hpp"


class Fwoosh: public ASpell
{
	private:

	public:
		Fwoosh();
		~Fwoosh();
		Fwoosh(const Fwoosh& other);
		Fwoosh& operator=(const Fwoosh& other);

		Fwoosh* clone() const;

};

#endif