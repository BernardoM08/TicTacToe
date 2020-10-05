#include <iostream>
using namespace std;

void draw();
void turn();
const int R = 3;
const int C = 3;
char board[R][C] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};

int main ()
{
  draw();
  bool running = true;
  while (running == true)
    {
      turn();
    }
  return 0;
}

void turn()
{
  int R = 3;
  int C = 3;
  char player;
  if (player == 'X')
    {
      player = 'O';
    }
  else
    {
      player = 'X';
    }
  cin >> R;
  cin >> C;
  board[R][C] = player;
  draw();
}

void draw()
{
  cout << "    0  1  2     ";
  cout << endl;
  cout << " 0  " << board[0][0] << "  " << board[0][1] << "  " << board[0][2] << endl;
  cout << " 1  " << board[1][0] << "  " << board[1][1] << "  " << board[1][2] << endl;
  cout << " 2  " << board[2][0] << "  " << board[2][1] << "  " << board[2][2] << endl;
}
