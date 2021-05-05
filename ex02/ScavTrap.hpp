#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &other);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap const &other);
		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void challengeNewcomer();
	private:
		static std::string quotes[5];
};

#endif
