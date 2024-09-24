#ifndef ATARGET_HPP
# define ATARGET_HPP
# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;

	public:
		ATarget(std::string Type);
		virtual ~ATarget();
		ATarget(const ATarget& other);
		ATarget& operator=(const ATarget& other);

		const std::string& getType() const;

		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell& spell) const;
};

#endif