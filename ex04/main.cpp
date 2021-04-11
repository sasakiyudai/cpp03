#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	std::srand(time(NULL));
	FragTrap hikakin("hikakin");
	ScavTrap seikin("seiikin");
	ClapTrap youtube("youtube");
	NinjaTrap nikoniko("nikoniko");
	NinjaTrap nikoniko2("nikoniko2");
	SuperTrap superman("superman");

	hikakin.rangedAttack("seikin");
	seikin.takeDamage(20);
	seikin.meleeAttack("hikakin");
	hikakin.takeDamage(20);
	nikoniko.meleeAttack("hikakin");
	hikakin.takeDamage(20);

	hikakin.meleeAttack("seikin");
	seikin.takeDamage(30);
	seikin.rangedAttack("hikakin");
	hikakin.takeDamage(15);
	nikoniko.rangedAttack("seikin");
	seikin.takeDamage(20);

	hikakin.meleeAttack("seikin");
	seikin.takeDamage(30);
	seikin.rangedAttack("nikoniko");
	nikoniko.takeDamage(15);
	nikoniko.rangedAttack("seikin");
	seikin.takeDamage(20);

	hikakin.beRepaired(30);
	seikin.beRepaired(40);
	nikoniko.beRepaired(40);

	hikakin.vaulthunter_dot_exe("seikin");
	seikin.challengeNewcomer();
	nikoniko.ninjaShoebox(hikakin);

	hikakin.vaulthunter_dot_exe("seikin");
	seikin.challengeNewcomer();
	nikoniko.ninjaShoebox(seikin);

	hikakin.vaulthunter_dot_exe("seikin");
	seikin.challengeNewcomer();
	nikoniko.ninjaShoebox(youtube);

	nikoniko.ninjaShoebox(nikoniko2);

	superman.meleeAttack("hikakin");
	superman.rangedAttack("seikin");

	superman.vaulthunter_dot_exe("nikoniko");
	superman.vaulthunter_dot_exe("nikoniko2");

	superman.ninjaShoebox(hikakin);
	superman.ninjaShoebox(seikin);
	superman.ninjaShoebox(youtube);
	superman.ninjaShoebox(nikoniko2);

	return (0);
}
