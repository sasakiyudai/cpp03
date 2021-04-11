#ifndef NINJA_TRAP_HPP
#define NINJA_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

class NinjaTrap: virtual public ClapTrap
{
	public:
		NinjaTrap(std::string const &name);
		NinjaTrap(NinjaTrap const &other);
		~NinjaTrap();

		NinjaTrap &operator=(NinjaTrap const &other);
		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void ninjaShoebox(FragTrap &ref);
		void ninjaShoebox(ScavTrap &ref);
		void ninjaShoebox(ClapTrap &ref);
		void ninjaShoebox(NinjaTrap &ref);
};

#endif
