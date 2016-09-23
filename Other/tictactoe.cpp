/*
Tic tac toe game using basic c++ functions

copyright Kristians Kanders
kandersk@uindy.edu
https://github.com/kandersk

*/

#include <iostream>

using namespace std;

int main()
{
  int turn = 1;
  char input = 0;
  char s1 = 49;
  char s2 = 50;
  char s3 = 51;
  char s4 = 52;
  char s5 = 53;
  char s6 = 54;
  char s7 = 55;
  char s8 = 56;
  char s9 = 57;
  char x = 'x';
  char o = 'o';
  char print = 0;
  
  int winner = 0;
  cout << endl;
  cout << "Welcome to tic tac toe, each square represents a number:" << endl;
  
  do
  {
    cout << endl << s1 << " │ " << s2 << " │ " << s3 << endl 
    << "──┼───┼──" << endl
    << s4 << " │ " << s5 << " │ " << s6 << endl 
    << "──┼───┼──" << endl 
    << s7 << " │ " << s8 << " │ " << s9 << endl;
    
    
    cout << "Slot: ";
    cin  >> input;
    
    if (turn % 2 == 1)
    {
      print = x;
    }
    else
    {
      print = o;
    }
    
    if (input == s1)
    {
      s1 = print;
    }
    else if (input == s2)
    {
      s2 = print;
    }
    else if (input == s3)
    {
      s3 = print;
    }
    else if (input == s4)
    {
      s4 = print;
    }
    else if (input == s5)
    {
      s5 = print;
    }
    else if (input == s6)
    {
      s6 = print;
    }
    else if (input == s7)
    {
      s7 = print;
    }
    else if (input == s8)
    {
      s8 = print;
    }
    else if (input == s9)
    {
      s9 = print;
    }
    
    if (s1 == s2 && s1 == s3)
    {
      winner = winner + 1;
    }
    else if (s4 == s5 && s4 == s6)
    {
      winner = winner + 1;
    }
    else if (s7 == s8 && s7 == s9)
    {
      winner = winner + 1;
    }
    else if (s1 == s5 && s1 == s9)
    {
      winner = winner + 1;
    }
    else if (s3 == s5 && s3 == s9)
    {
      winner = winner + 1;
    }
    
    if (winner == 1)
    {
      cout << endl << s1 << " │ " << s2 << " │ " << s3
      << "\n──┼───┼──\n" << s4 << " │ " << s5 << " │ " << s6
      << "\n──┼───┼──\n" << s7 << " │ " << s8 << " │ " << s9
      << endl;
      
      if (print == x)
      {
        cout << "Congratulations player 1, you are victorious!" << endl;
      }
      else
      {
        cout << "Congratulations player 2, you have beaten the odds!" << endl;
      }
    }
    turn ++;
  }
  while (winner == 0);
  
  cout << "Game over in " << turn << " turns" << endl;

  
  
  return 0;
}