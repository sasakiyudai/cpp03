#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::srand(time(NULL));
	FragTrap hikakin("hikakin");
	ScavTrap seikin("seiikin");

	hikakin.rangedAttack("seikin");
	seikin.takeDamage(20);
	seikin.meleeAttack("hikakin");
	hikakin.takeDamage(20);

	hikakin.meleeAttack("seikin");
	seikin.takeDamage(30);
	seikin.rangedAttack("hikakin");
	hikakin.takeDamage(15);

	hikakin.meleeAttack("seikin");
	seikin.takeDamage(30);
	seikin.rangedAttack("hikakin");
	hikakin.takeDamage(15);

	hikakin.beRepaired(30);
	seikin.beRepaired(40);

	hikakin.vaulthunter_dot_exe("seikin");
	seikin.challengeNewcomer();

	hikakin.vaulthunter_dot_exe("seikin");
	seikin.challengeNewcomer();

	hikakin.vaulthunter_dot_exe("seikin");
	seikin.challengeNewcomer();

	return (0);
}
