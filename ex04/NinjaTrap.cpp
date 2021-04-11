#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(std::string const &name):ClapTrap(name)
{
	std::cout << "just constructing Ninja!" << std::endl;hitPoints = 100;
	hitPoints = 60;
	maxHitPoints = 60;
	energyPoints = 120;
	maxEnergyPoints = 120;
	level = 1;
	meleeAttackDamage = 60;
	rangedAttackDamage = 5;
	armorDamageReduction = 0;
}

NinjaTrap::NinjaTrap(NinjaTrap const &other):ClapTrap(other.name)
{
	std::cout << "just constructing Ninja!" << std::endl;
	*this = other;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "just destructing Ninja!" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &other)
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

void NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "Ninja " << this->name << " attacks " << target << " at range, causing " << this->rangedAttackDamage << " points of damage!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "Ninja " << this->name << " attacks " << target << " at melee, causing " << this->meleeAttackDamage << " points of damage!" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &ref)
{
	if (this->energyPoints >= 5)
	{
		this->energyPoints -= 5;
		std::cout << "Ninja " << this->name << " made kagebunshin to " << ref.nameGetter() <<"!" << std::endl;
		std::cout << ref.nameGetter() << " " << "feels so bad!" << std::endl;
	}
	else
	{
		std::cout << this->name << " is out of energy..." << std::endl;
	}
}

void NinjaTrap::ninjaShoebox(ScavTrap &ref)
{
	if (this->energyPoints > 10)
	{
		this->energyPoints -= 10;
		std::cout << "Ninja " << this->name << " throw syuriken to " << ref.nameGetter() <<"!" << std::endl;
		ref.takeDamage(20);
	}
	else
	{
		std::cout << "Ninja " << this->name << " throw syuriken to " << ref.nameGetter() <<"!" << std::endl;
		std::cout << "But " << ref.nameGetter() << " avoid all!" << std::endl;
	}
}

void NinjaTrap::ninjaShoebox(ClapTrap &ref)
{
	if (this->energyPoints > 20)
	{
		this->energyPoints -= 20;
		std::cout << "Ninja " << this->name << " tried to attack " << ref.nameGetter() <<"!" << std::endl;
		std::cout << "But Nothing happend!" << std::endl;
	}
	else
	{
		std::cout << this->name << " is out of energy..." << std::endl;
	}
}

void NinjaTrap::ninjaShoebox(NinjaTrap &ref)
{
	if (this->energyPoints > 15)
	{
		this->energyPoints -= 15;
		std::cout << "Ninja " << this->name << " attack " << ref.nameGetter() <<"!" << std::endl;
		ref.takeDamage(10);
	}
	else
	{
		std::cout << this->name << " is out of energy..." << std::endl;
	}
}
