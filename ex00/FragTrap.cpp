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

FragTrap::FragTrap(std::string const &name):name(name)
{
	std::cout << "Hey, best friend! Constructing for you!" << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
}

FragTrap::FragTrap(FragTrap const &other)
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
	std::cout << "FR4G-TP" << this->name << "attacks" << target << "at range, causing" << this->rangedAttackDamage << "points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP" << this->name << "attacks" << target << "at melee, causing" << this->meleeAttackDamage << "points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	int actualDamage;

	actualDamage = amount - this->armorDamageReduction;
	this->hitPoints -= actualDamage;
	if (this->hitPoints < 0)
	{
		actualDamage += this->hitPoints;
		this->hitPoints = 0;
	}
	std::cout << "FR4G-TP" << this->name << "takes" << actualDamage << "points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	if (this->hitPoints > this->maxHitPoints)
	{
		amount -= (this->hitPoints - this->maxHitPoints);
		this->hitPoints = this->maxHitPoints;
	}
	std::cout << "FR4G-TP" << this->name << "is repaired" << amount << "points!" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->energyPoints < 25)
	{
		std::cout << "FR4G-TP" << this->name << "is out of energy..." << std::endl;
	}
	else
	{
		this->energyPoints -= 25;
		std::cout << "FR4G-TP" << this->name << "attacks" << target << "saying \"" << FragTrap::quotes[std::rand() % 5] << "\" causing" << std::rand() % 100 << "points of damage!" << std::endl;
	}
}
