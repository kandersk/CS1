#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
  int dice = 0;
  string ans = "";
  cout << "How many sides of your dice: ";
  cin  >> dice;
  
  srand (time(0));
  
  do
  {
    cout << "You rolled: " << rand() % dice + 1 << endl;
  
    cout << "Do you want to roll again? (Yes/No)" << endl;
    cin  >> ans;
  }
  while (ans == "Yes" || ans == "yes" || ans == "y" || ans == "Y");
  
  return 0;
}