#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock(const Warlock& other);
		Warlock& operator=(const Warlock& other);

	public:
		Warlock(const std::string& Name, const std::string& Title);
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void setTitle(const std::string& Title);
		void introduce() const;
};

#endif