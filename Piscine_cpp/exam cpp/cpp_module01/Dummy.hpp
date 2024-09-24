#ifndef DUMMY_HPP
# define DUMMY_HPP
# include <iostream>
# include "ATarget.hpp"

class Dummy: public ATarget
{
	public:
		Dummy();
		~Dummy();
		Dummy(const Dummy& other);
		Dummy& operator=(const Dummy& other);

		const std::string& getType() const;

		Dummy* clone() const;
		
};

#endif