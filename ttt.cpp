#include <iostream>
#include <cstring>
using namespace std;

// golbal functions and constants
bool checkwinX();
bool checkwinO();
bool checktie();
void draw();
void blank();
const int R = 3;
const int C = 3;
const char player = 'X';
char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

int main ()
{
  // variables 
  bool running = true;
  bool game = true;
  char player = 'X';
  char yn;
  int R = 3;
  int C = 3;
  int Xwin = 0;
  int Owin = 0;
  // while loop that determines whether you can restart the game or not
  while (running == true)
    { // while loop that determines whether the TTT game is currently running
      while (game == true)
	{
	  draw();
	  // you can input a character for the row. If your input isn't a valid option, pick again
	  cout << "Choose a row" << endl;
	  cin >> R;
	  while (R != 0 && R != 1 && R != 2)
	    {
	      cout << "Please pick another row" << endl;
	      cin >> R;
	    }
	  // you can input a character for the column. If your input isn't a valid option, pick again.
	  cout << "Choose a column" << endl;
	  cin >> C;
	  while (C != 0 && C != 1 && C != 2)
	    {
	      cout << "Please pick another column" << endl;
	      cin >> C;
	    }
	  // checks if the space on the board is blank. If yes, change the spot to whichever team's turn it is. Checks to see if there is a tie.
	  if (board[R][C] == ' ')
	    {
	      board[R][C] = player;
	      checktie();
	      if (checktie() == true)
		{
		  game = false;
		}
	      // checks if it is X's turn. If yes, check if X has won. If yes again, end the game. If no, switch the turn to O and continue the game.
	      else if (player == 'X')
		{
		  checkwinX();
		  if (checkwinX() == true)
		    {
		      Xwin++;
		      game = false;
		    }
		  player = 'O';
		}
              
	      // If it isn't X's turn, check if O has won. If yes again, end the game. If no, switch the turn to X and continue the game.
	      else
		{
		  checkwinO();
		  if(checkwinO() == true)
		    {
		      Owin++;
		      game = false;
		    }
		  player = 'X';
		}
	    }
          // If the spot isn't blank, pick a new spot.
	  else
	    {
	      cout << "Please pick a new spot that's is not taken" << endl;
	    }
	}
      // displays the current wins for each team and asks whether the player wants to continue playing. If yes, restart the game, restart the board, and switch it back to X's turn. If no, end the function.
      cout << "X Wins: " << Xwin << endl;
      cout << "O Wins: " << Owin << endl;
      cout << "Would you like to play again? 'y' for yes, 'n' for no" << endl;
      cin >> yn;
      while (yn != 'y' && yn != 'n')
	{
	  cout << "'y' for yes, 'n' for no" << endl;
	  cin >> yn;
	}
      if (yn == 'y')
	{
	  blank();
	  game = true;
	  player = 'X';
	}
      else if (yn == 'n')
	{
	  cout << "Thanks for playing!" << endl; 
	  running = false;
	}
    }
  return 0;
}
// checks whether there are still blank squares on the grid. If yes, return false. If no, return true.
bool checktie()
{
  for (int r = 0; r < 3; r++)
    {
      for (int c = 0; r < 3; c++)
	{
	  if (board[r][c] == ' ')
	    {
	      return false;
	    }
	}
    }
  return true;
}
// checks if there are 3 X's in a line. If yes, return true. If no, return false.
bool checkwinX()
{
  if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
    {
	return true;
    }
  if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
    {

	return true;
    }
  if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
    {

	return true;
    }
  if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
    {

	return true;
    }
  if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
    {

	return true;
    }
  if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
    {

	return true;
    }
  if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    {

	return true;
    }
  if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
    {

	return true;
    }
return false;
}
// checks if there are 3 O's in a line. If yes, return true. If no, return false.
bool checkwinO()
{
  if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
    {
	return true;
    }
  if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
    {

	return true;
    }
  if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] ==  'O')
    {

	return true;
    }
  if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
    {

	return true;
    }
  if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
    {

	return true;
    }
  if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
    {

	return true;
    }
  if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {

	return true;
    }
  if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
    {

	return true;
    }
return false;
}
// sets all the squares on the grid to blank
void blank()
{
  board[0][0] = ' ';
  board[1][0] = ' ';
  board[2][0] = ' ';
  board[0][1] = ' ';
  board[1][1] = ' ';
  board[2][1] = ' ';
  board[0][2] = ' ';
  board[1][2] = ' ';
  board[2][2] = ' ';
}
// outputs the layout of the grid, which includes labels for the positions and updates each of the spaces as the  game continues 
void draw()
{
  cout << "    0  1  2     ";
  cout << endl;
  cout << " 0  " << board[0][0] << "  " << board[0][1] << "  " << board[0][2] << endl;
  cout << " 1  " << board[1][0] << "  " << board[1][1] << "  " << board[1][2] << endl;
  cout << " 2  " << board[2][0] << "  " << board[2][1] << "  " << board[2][2] << endl;
}
