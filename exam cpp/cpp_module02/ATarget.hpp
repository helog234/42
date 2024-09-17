#pragma once
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string type;

	public:
		ATarget(const std::string& Type);
		virtual ~ATarget();
		ATarget(const ATarget& other);
		ATarget& operator=(const ATarget& other);

		const std::string& getType();

		virtual ATarget* clone() const = 0;

		void getHitBySpell(const ASpell& spell) const;
};

#endif