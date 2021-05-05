#ifndef SUPER_TRAP_HPP
#define SUPER_TRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>

class SuperTrap: public FragTrap, public NinjaTrap
{
	private:
		SuperTrap();
	public:
		SuperTrap(std::string const &name);
		SuperTrap(SuperTrap const &other);
		~SuperTrap();

		SuperTrap &operator=(SuperTrap const &other);
		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
	private:
};

#endif
