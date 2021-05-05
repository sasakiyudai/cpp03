#include "FragTrap.hpp"
#include <iostream>

std::string FragTrap::quotes[5] = 
{
	"Let me teach you the ways of magic!",
	"Still working on that quest?",
	"Ahhh!",
	"Hocus pocus!",
	"Gosh. This party is worse than stairs."
};

FragTrap::FragTrap():ClapTrap()
{

}

FragTrap::FragTrap(std::string const &name):ClapTrap(name)
{
	std::cout << "Hey, best friend! Constructing myself for you!" << std::endl;
	energyPoints = 100;
	maxEnergyPoints = 100;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
}

FragTrap::FragTrap(FragTrap const &other):ClapTrap(other.name)
{
	std::cout << "Hey, best friend! Constructing for you!" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "Yessss, look into my eyes. You're getting sleepy. You're getting... zzzzzz... Zzzzzz..." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	hitPoints = other.hitPoints;
	maxHitPoints = other.maxEnergyPoints;
	energyPoints = other.energyPoints;
	maxEnergyPoints = other.maxEnergyPoints;
	level = other.level;
	meleeAttackDamage = other.meleeAttackDamage;
	rangedAttackDamage = other.rangedAttackDamage;
	armorDamageReduction = other.armorDamageReduction;
	return (*this);
}

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " at range, causing " << this->rangedAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " at melee, causing " << this->meleeAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->energyPoints < 25)
	{
		std::cout << "FR4G-TP " << this->name << " is out of energy..." << std::endl;
	}
	else
	{
		this->energyPoints -= 25;
		std::cout << "FR4G-TP " << this->name << " attacks " << target << " saying \"" << FragTrap::quotes[std::rand() % 5] << "\" causing " << std::rand() % 100 << " points of damage!" << std::endl;
	}
}
