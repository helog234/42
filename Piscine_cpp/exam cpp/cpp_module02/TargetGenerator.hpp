#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP
# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> book;
		TargetGenerator(const TargetGenerator& other);
		TargetGenerator& operator=(const TargetGenerator& other);

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string type);
		ATarget* createTarget(const std::string& type);
};

#endif