#pragma once
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string name;
		std::string effects;

	public:
		ASpell(const std::string& Name, const std::string& Effects);
		virtual ~ASpell();
		ASpell(const ASpell& other);
		ASpell& operator=(const ASpell& other);

		const std::string& getName() const;
		const std::string& getEffect() const;

		virtual ASpell* clone() const = 0;
		void launch(const ATarget& target);
};

#endif