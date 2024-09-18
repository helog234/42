#ifndef ASPELL_HPP
# define ASPELL_HPP
# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:

	
	protected:
		std::string name;
		std::string effect;

	public:
		ASpell(const std::string& Name, const std::string& Effect);
		virtual ~ASpell();
		ASpell(const ASpell& other);
		ASpell& operator=(const ASpell& other);

		const std::string& getName() const;
		const std::string& getEffect() const;

		virtual ASpell* clone() const = 0;

		void launch(const ATarget& target);
};

#endif