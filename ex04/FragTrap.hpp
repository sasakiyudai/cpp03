#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	protected:
		FragTrap();
	public:
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &other);
		~FragTrap();

		FragTrap &operator=(FragTrap const &other);
		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void vaulthunter_dot_exe(std::string const &target);
	private:
		static std::string quotes[5];
};

#endif
