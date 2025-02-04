
#include "ClapTrap.hpp"

// int main(void)
// {
// 	std::cout << "\033[33m" << std::endl << "Showing ClapTrap constructors" << "\033[0m" << std::endl;

// 	ClapTrap default_clap;
// 	ClapTrap tim("Tim");
// 	ClapTrap copy_tim(tim);
// 	ClapTrap bernd("Bernd");


// 	std::cout << "\033[33m" << std::endl << "Tests for ClapTrap functions" << "\033[0m" << std::endl;
// 	std::cout << "Tim has " << tim.get_hit_points() << " hit points and " << tim.get_energy_points() << " energy points left" << std::endl;
// 	tim.attack("a bear");
// 	tim.takeDamage(2);
// 	std::cout << "Tim has " << tim.get_hit_points() << " hit points and " << tim.get_energy_points() << " energy points left" << std::endl;


// 	std::cout << "\033[33m" << std::endl << "Tests for being dead" << "\033[0m" << std::endl;
// 	std::cout << "Bernd has " << bernd.get_hit_points() << " hit points and " << bernd.get_energy_points() << " energy points left" << std::endl;
// 	bernd.takeDamage(11);
// 	bernd.attack("house");
// 	bernd.beRepaired(5);
// 	bernd.takeDamage(5);
// 	std::cout << "Bernd has " << bernd.get_hit_points() << " hit points and " << bernd.get_energy_points() << " energy points left" << std::endl;
	

// 	std::cout << "\033[33m" << std::endl << "Tests for ClapTrap copy constructor and assignment operator" << "\033[0m" << std::endl;
// 	std::cout << "CopyTim has " << copy_tim.get_hit_points() << " hit points and " << copy_tim.get_energy_points() << " energy points left" << std::endl;
// 	copy_tim = tim;
// 	std::cout << "CopyTim has " << copy_tim.get_hit_points() << " hit points and " << copy_tim.get_energy_points() << " energy points left" << std::endl;


// 	std::cout << "\033[33m" << std::endl << "Deconstructor calling" << "\033[0m" << std::endl;

// 	return (0);
// }

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}