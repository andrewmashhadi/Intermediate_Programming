#include "Tic_tac_toe.h"

int main()
{

	size_t n_games;
	std::cout << "Number of games: ";
	std::cin >> n_games;
	std::string name_1;
	std::string name_2;
	std::cout << "Player 1 Name = ";
	// Removing the remaining newline character in buffer
	std::cin.ignore();
	std::getline(std::cin, name_1);
	std::cout << "Player 2 Name = ";
	std::getline(std::cin, name_2);
	Person player_1(name_1);
	Person player_2(name_2);
	std::cout << "     Tic Tac Toe" << std::endl;
	std::string names_heading = name_1 + " (X) - " + name_2 + " (O)";

	// If length of names and characters heading is too short then we should try to center it by adding spaces.
	if (names_heading.length() < 24)
	{
		// Loop to add appropriate spaces before the names heading is printed, to help center it.
		for (size_t i = 0; i < (12 - names_heading.length() / 2); i++)
			std::cout << ' ';
	}
	std::cout << names_heading <<'\n'<< std::endl;
	Game game_1(&player_1, &player_2, n_games);
	game_1.play_games();
	
	return 0;
}
