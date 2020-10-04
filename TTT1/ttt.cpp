#include <iostream>
using namespace std;

void draw();
char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};

int main ()
{
  char turn = 'X';
  draw();
  
  return 0;
}

void draw()
{
  cout << "    1  2  3     ";
  cout << endl;
  cout << " a  " << board[0][0] << "  " << board[0][1] << "  " << board[0][2] << endl;
  cout << " b  " << board[1][0] << "  " << board[1][1] << "  " << board[1][2] << endl;
  cout << " c  " << board[2][0] << "  " << board[2][1] << "  " << board[2][2] << endl;
  
}
