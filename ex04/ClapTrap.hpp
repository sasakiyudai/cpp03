#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
	public:
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &other);
		virtual ~ClapTrap();

		ClapTrap &operator=(ClapTrap const &other);
		virtual void rangedAttack(std::string const &target);
		virtual void meleeAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string const nameGetter();
	protected:
		int hitPoints;
		int maxHitPoints;
		int energyPoints;
		int maxEnergyPoints;
		int level;
		std::string name;
		int meleeAttackDamage;
		int rangedAttackDamage;
		int armorDamageReduction;
};

#endif