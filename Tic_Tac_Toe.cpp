#include "Tic_tac_toe.h"

// Default constructor for a person object, sets the name to a white space (empty) and score to 0.
Person::Person() : name(" "), score(0) {}

/* Overloaded constructor with a parameter that sets name equal to its parameter and sets score to 0.
@param n the string to set name to
*/
Person::Person(const std::string &n) : name(n), score(0) {}

/* Accessor member function for person's name.
@return the name member variable of this person object
*/
std::string Person::getName() const
{
	return name;
}
/* Accessor member function for person's score.
@return the score member variable of this person object
*/
int Person::getScore() const
{
	return score;
}
/* Increments this object's score member variable by 1 point.
@return void
*/
void Person::IncScore()
{
	score++;
}

/* Default constructor for this Game object sets the person pointers (p_1, p_2) to NULL,
the number of game (n_games) equal to 0, and fills the vector grid with 3 string vectors
each with 3 blank space (empty) strings.
*/
Game::Game()
{
	p_1 = nullptr;
	p_2 = nullptr;
	n_games = 0;
	std::vector<std::string> blank_row(BRD_SIZE, " ");

	// Loop fills our grid vector member with 3 vectors, each filled with 3 empty-space strings.
	for (size_t i = 0; i < BRD_SIZE; i++)
	{
		grid.push_back(blank_row);
	}
	print_grid();
}

/* Overloaded constructor with parameters for this Game object sets the person pointers (p_1, p_2)
equal to the pointers passed in as parameters, sets the number of games (n_games) equal to the 
number of games parameter passed in, and fills the vector grid with 3 string vectors
each with 3 blank space (empty) strings. Displays the empty grid/board right away.
@param player1 points to a Person object containing the first player's information, for p_1 to be set to
@param player2 points to a Person object containing the second player's information, for p_2 to be set to
@param n is the number of games the players would like to play, for n_games to be set to
*/
Game::Game(Person* player1, Person* player2, size_t n)
{
	p_1 = player1;
	p_2 = player2;
	n_games = n;
	std::vector<std::string> blank_row(BRD_SIZE, " ");

	// Loop fills our grid vector member with 3 vectors, each filled with 3 empty-space strings.
	for (size_t i = 0; i < BRD_SIZE; i++)
	{
		grid.push_back(blank_row);
	}
	print_grid();
}
/* Private member function used to scan the board to see if the player corresponding to "ch" parameter has won.
@param ch is the "X" or "O" string that has most recently been marked on the baord 
@return bool that is true if the the board shows player associated with "ch" has won, false if player hasn't won
*/
bool Game::has_won(const std::string &ch) const
{
	// Checking for a win by three in a column.

	// Loop to iterate through each column of the 2D-grid vector.
	for (size_t col = 0; col < BRD_SIZE; col++)
	{
		size_t c_marks = 0;
		// Loop to iterate through each row of the grid, holding the column constant as col.
		for (size_t row = 0; row < BRD_SIZE; row++)
		{
			// If the 2D-grid vector equals the "ch" string at row "row" and column "col", we increment c_marks by one.
			if (grid[row][col] == ch)
				c_marks++;
		}
		/* If c_marks equals 3, then the "col" column is filled with 3 of the same charactors, and 
		the player associated with the "ch" string has won, so we return true.
		*/
		if (c_marks == BRD_SIZE)
			return true;
	}
	//Checking for a win by three in a row.

	// Loop to iterate through each row of the 2D-grid vector.
	for (size_t row = 0; row < BRD_SIZE; row++)
	{
		size_t r_marks = 0;
		// Loop to iterate through each column of the 2D-grid vector, holding the row constant (variable "row").
		for (size_t col = 0; col < BRD_SIZE; col++)
		{
			// If the 2D-grid vector equals the "ch" string at row "row" and column "col", we increment r_marks by one 
			if (grid[row][col] == ch)
				r_marks++;
		}
		/* If r_marks equals 3, then the "row" row is filled with 3 of the same characters, and
		the player associated with the "ch" string has won, so we return true.
		*/
		if (r_marks == BRD_SIZE)
			return true;
	}

	// Checking for a win by three in a diagonal.

	size_t d_marks = 0;
	// Iterates through the diagonal of the 2D-grid vector, going from top left corner to bottom right corner.
	for (size_t i = 0; i < BRD_SIZE; i++)
	{
		// If the 2D-grid vector equals the "ch" string at row "row" and column "col", we increment d_marks by one 
		if (grid[i][i] == ch)
			d_marks++;
	}
	/* If d_marks equals 3, then each entry on the diagonal going from the top left corner to bottom right corner 
	is filled with the same character, and the player associated with the "ch" string has won, so we return true.
	*/
	if (d_marks == BRD_SIZE)
		return true;

	d_marks = 0;
	// Iterates through the diagonal of the 2D-grid vector, going from bottom left corner to top right corner.
	for (size_t i = 0; i < BRD_SIZE; i++)
	{
		// If the 2D-grid vector equals the "ch" string at row "row" and column "col", we increment d_marks by one.
		if (grid[2-i][i] == ch)
			d_marks++;
	}
	/* If d_marks equals 3, then each entry on the diagonal going from the bottom left corner to top right corner
	is filled with the same character, and the player associated with the "ch" string has won, so we return true.
	*/
	if (d_marks == BRD_SIZE)
		return true;

	return false;
}
/* Private member function used to check if the board is full of non-empty strings in each location.
@return bool is true if board/grid is full of non-empty strings in each location, false if a space is still empty
*/
bool Game::full()
{
	// Loop to iterate through each row of the 2D-grid vector.
	for (size_t i = 0; i < BRD_SIZE; i++)
	{
		// Loop to iterate through each column of the 2D-grid vector, holding the row constant (variable "row").
		for (size_t j = 0; j < BRD_SIZE; j++)
		{
			// If the 2D-grid vector equals an empty space, then it is not full yet. Return false.
			if (grid[i][j] == " ")
				return false;
		}
	}
	return true;
}

/* Private member function sets all the locations on the board back to empty (white space) strings
in order to play another game.
@return void
*/
void Game::clear_grid()
{
	// Loop to iterate through each row of the 2D-grid vector.
	for (size_t i = 0; i < BRD_SIZE; i++)
	{
		// Loop to iterate through each column of the 2D-grid vector, holding the row constant (variable row).
		for (size_t j = 0; j < BRD_SIZE; j++)
		{
			grid[i][j] = " ";
		}
	}
}

/* Private member function, providing enough space to use before a gird/board printing. This helps to give the 
appearence of a screen update.
@return void
*/
void Game::provide_space() const
{
	std::string fifty_spaces = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << fifty_spaces;
}

/* Private member function used to mark a location and calls has_won and full functions to see if 
the current game is over. Calls clear_board function if board/grid needs to be reset. Performs bounds 
checking and checks to make sure location has not already been set in the same game.
@param player is a pointer to a Person object, either the p_1 or p_2 is passed depending on whose turn it is
@param sym is either the "X" or "O" string, depending on whose turn it is to mark the board
@param done is a bool variable passed by reference, set to true if player wins or if the board is full 
@return void*/
void Game::mark_location(Person* player, const std::string &sym, bool &done)
{
	int in_row, in_col;
	bool in_error;
	std::cout << player->getName() << " (" << sym << ") Mark Location:  ";
	std::cin >> in_row >> in_col;
	std::cout << '\n';

	/* Do-while loop to validate both to make sure the input row or column is within the grid vector's
	bounds and to also make sure the input location has not already been marked.
	*/
	do
	{
		in_error = false;
		// If the chosen row or column is ouside of the 2D-grid vector's bounds, prompt user for entries again.
		if (in_row < 1 || in_col < 1 || in_row > 3 || in_col > 3)
		{
			std::cout << "That location is not on the board. Please mark a different location:  ";
			std::cin >> in_row >> in_col;
			in_error = true;
		}
		// Otherwise if the chosen row and column has already been marked on this game's grid,  
		else if (grid[in_row - 1][in_col - 1] != " ")
		{
			std::cout << "That location has already been marked. Please mark a different location:  ";
			std::cin >> in_row >> in_col;
			in_error = true;
		}
	} while (in_error);

	grid[in_row - 1][in_col - 1] = sym;

	/* If the player corresponding to the string most recently marked on the grid/board has won, 
	we print the final board, the name of the winner, increment the winner, empty the 2D-grid vector,
	and set done to true since this game is finished.
	*/
	if (has_won(sym))
	{
		provide_space();
		print_grid();
		std::cout << player->getName() << " wins this round" << std::endl;
		player->IncScore();
		clear_grid();
		done = true;
	}
	/* Otherwise if the grid/board has no more empty spaces left, we print the final board. Since neither player 
	has won and the board is full, we have a tie. Clear the board and set done to true to move on to the next game.
	*/
	else if (full())
	{
		provide_space();
		print_grid();
		std::cout << "The board is full! This game is a tie! Neither player's score will increase." << std::endl;
		clear_grid();
		done = true;
	}
}

/* Member function prints out the current board/grid displaying each vector string value, empty
or not, in its individual quadrant area on the tic-tac-toe board.
@return void
*/
void Game::print_grid() const
{
	int mod3_count = 0;
	// Loop to iterate through all ten lines to create the board as in homework specifications
	for (size_t line = 1; line <= 10; line++)
	{
		// If we are printing the first line, we have to print a 1,2,3 as shown in output description.
		if (line == 1)
		{
			std::cout << std::setw(6) << 1 << std::setw(7) << 2 << std::setw(8) << 3 << std::endl;
		}
		// Otherwise if we are printing the board's 4th or 7th line, we have this divider as shown in output instructions. 
		else if (line == 4 || line == 7)
		{
			std::cout << "  _______|_______|_____" << std::endl;
		}
		/* Otherwise if we are printing the board's 3rd,6th,9th line, we display the corresponding values of
		the 2D-grid vectors as shown in the output intructions
		*/
		else if (line % 3 == 0)
		{
			std::cout << mod3_count + 1 << std::setw(4) << grid[mod3_count][0] << std::setw(5) << '|';
			std::cout << std::setw(4) << grid[mod3_count][1] << std::setw(4) << '|' << std::setw(4) << grid[mod3_count][2] << std::endl;
			mod3_count++;
		}
		// Otherwise if the we are printing any other lines for the board, the output should be the following barriers.
		else
		{
			std::cout << std::setw(10) << '|' << std::setw(8) << '|' << std::endl;
		}
	}
	std::cout << '\n';
}

/* Member function that runs the game. First iteritively calls the mark_location function for each 
player to mark their loaction on the board with their corresponding "X" or "O", alternating on each turn. 
Prints game results and cleared board after each game iteration (unless no more games left), then 
prints the results of the overall winner (whichever player's score is larger)
@return void
*/
void Game::play_games()
{
	// For loop to iterate through all the games of tic-tac-toe as requested by the user.
	for (size_t game = 1; game <= n_games; game++)
	{
		bool done = false;
		size_t turn = 1;
		/* Loop to iterate through a single game of tic-tac-toe. Alternating between each player to
		mark their next location. Loop finsihes once done is set to true by either the board being full 
		or a player winning the game.
		*/
		while (!done)
		{
			// If turn is even, it is the "O" player's turn. Otherwise, it is the "X" player's turn. 
			if (turn % 2 == 0)
				mark_location(p_2, "O", done);
			else
				mark_location(p_1, "X", done);

			// If we are not done, then the newest board update hasn't been shown, so we display it for the next marking.
			if (!done)
			{
				provide_space();
				print_grid();
			}
			turn++;
		}
		size_t largest_name;
		/* If the first player's name is longer than the second player's name, set largest_name as the 
		length of first. Otherwise, set the largest_name as the length of the second player's name.
		*/
		if ((p_1->getName()).length() > (p_2->getName()).length())
			largest_name = (p_1->getName()).length();
		else
			largest_name = (p_2->getName()).length();

		std::cout << std::setw(largest_name) << p_1->getName() << " : " << p_1->getScore() << std::endl;
		std::cout << std::setw(largest_name) << p_2->getName() << " : " << p_2->getScore() << std::endl;
		
		// If we still have more games left, print the cleared grid/board to start off the next game.
		if (game < n_games)
		{
			std::cout << "\n(press [Enter] to continue to the next round...)";
			// Removing the remaining newline character in buffer
		    std::cin.ignore();		
			std::cin.get();
			provide_space();
			std::cout << "\nNext Game!\n" << std::endl;
			print_grid();
		}
	}
	// If the first player's score is larger than the second player's score, display them as the winner.
	if (p_1->getScore() > p_2->getScore())
		std::cout << "Congratulations " << p_1->getName() << " . You Won!" << std::endl;
	// Otherwise if the second player's score is larger than the first player's score, display them as the winner.
	else if (p_1->getScore() < p_2->getScore())
		std::cout << "Congratulations " << p_2->getName() << " . You Won!" << std::endl;
	// If the scores of the two player's are equal, display them that it was a tie. 
	else
		std::cout << "Each player has " << p_1->getScore() << " point(s). We have a tie!" << std::endl;
}
