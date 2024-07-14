#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap(void);
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap& other);
		ScavTrap &operator=(const ScavTrap& other);
        virtual ~ScavTrap();
		void attack(const std::string& target);
		void guardGate();

	protected:
		static const unsigned int	_initHit = 100;
		static const unsigned int	_initEnergy = 50;
		static const unsigned int	_initAttack = 20;
};

#endif

