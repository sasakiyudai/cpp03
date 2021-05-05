#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(std::string const &name):ClapTrap(name),FragTrap(name),NinjaTrap(name)
{
	std::cout << "Super Constructing!" << std::endl;
	hitPoints = FragTrap::hitPoints;
	maxHitPoints = FragTrap::maxEnergyPoints;
	energyPoints = NinjaTrap::energyPoints;
	maxEnergyPoints = NinjaTrap::maxEnergyPoints;
	meleeAttackDamage = NinjaTrap::meleeAttackDamage;
	rangedAttackDamage = FragTrap::rangedAttackDamage;
	armorDamageReduction = FragTrap::armorDamageReduction;
}

SuperTrap::SuperTrap(SuperTrap const &other):ClapTrap(name),FragTrap(other.name),NinjaTrap(other.name)
{
	std::cout << "Super Constructing!" << std::endl;
	*this = other;
}

SuperTrap::~SuperTrap()
{
	std::cout << "Super Destructing!" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &other)
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

void SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}
