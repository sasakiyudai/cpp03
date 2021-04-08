#include "FragTrap.hpp"

int main()
{
	std::srand(time(NULL));
	FragTrap hikakin("hikakin");

	hikakin.rangedAttack("seikin");
	hikakin.takeDamage(10);

	hikakin.meleeAttack("hikakin");
	hikakin.takeDamage(8);
	hikakin.takeDamage(4);

	hikakin.meleeAttack("seikin");
	hikakin.takeDamage(18);

	hikakin.beRepaired(40);
	hikakin.takeDamage(15);

	hikakin.vaulthunter_dot_exe("seikin");
	hikakin.takeDamage(10);

	hikakin.vaulthunter_dot_exe("seikin");
	hikakin.takeDamage(15);

	hikakin.vaulthunter_dot_exe("seikin");
	hikakin.takeDamage(10);

	return (0);
}
