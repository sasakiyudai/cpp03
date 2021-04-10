#include "ScavTrap.hpp"
#include <iostream>

std::string ScavTrap::quotes[5] = 
{
	"I got quests!",
	"There's more to learn!",
	"Shouldn't you be murdering something about now?",
	"Sooooo... how are things?",
	"Hey! You're TALKING to me! And I didn't even have an exclamation point over my head! This is the BEST day of my life!"
};

ScavTrap::ScavTrap(std::string const &name):name(name)
{
	std::cout << "Wooooooooooooooo! Constructing myself only for myself!" << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	level = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	armorDamageReduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	std::cout << "Wooooooooooooooo! Constructing myself only for myself!" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Wooooooooooooooo! Destructing myself only for myself!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
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

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "CL4P-TP " << this->name << " attacks " << target << " at range, causing " << this->rangedAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "CL4P-TP " << this->name << " attacks " << target << " at melee, causing " << this->meleeAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	int actualDamage;

	actualDamage = amount - this->armorDamageReduction;
	this->hitPoints -= actualDamage;
	if (this->hitPoints < 0)
	{
		actualDamage += this->hitPoints;
		this->hitPoints = 0;
	}
	std::cout << "CL4P-TP " << this->name << " takes " << actualDamage << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	if (this->hitPoints > this->maxHitPoints)
	{
		amount -= (this->hitPoints - this->maxHitPoints);
		this->hitPoints = this->maxHitPoints;
	}
	std::cout << "CL4P-TP " << this->name << " is repaired " << amount << " points!" << std::endl;
}

void ScavTrap::challengeNewcomer()
{
	std::cout << "CL4P-TP " << this->name << " says \"" << ScavTrap::quotes[rand() % 5] << "\"" << std::endl;
}
