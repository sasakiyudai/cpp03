#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
{
	
}

ClapTrap::ClapTrap(std::string const &name):name(name)
{
	std::cout << "Construction in ClapTrap" << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	level = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	armorDamageReduction = 3;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "Construction in ClapTrap" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destruction in ClapTrap" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
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

void ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "virtual " << target << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "virtual " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int actualDamage;

	actualDamage = amount - this->armorDamageReduction;
	this->hitPoints -= actualDamage;
	if (this->hitPoints < 0)
	{
		actualDamage += this->hitPoints;
		this->hitPoints = 0;
	}
	std::cout << this->name << " takes " << actualDamage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	if (this->hitPoints > this->maxHitPoints)
	{
		amount -= (this->hitPoints - this->maxHitPoints);
		this->hitPoints = this->maxHitPoints;
	}
	std::cout << this->name << " is repaired " << amount << " points!" << std::endl;
}