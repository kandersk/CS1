/*
Program that takes two integers (one low and one high and outputs 
the sum, the square the amount of even numbers,
the amount of numbers that end with a 0 (i.e. 10, 100, 1000)
of all integers from the lowest to the highest.

Kristians Kanders
kandersk@uindy.edu
*/
#include <iostream>

using namespace std;

int main ()
{
  int low = 0;
  int high = 0;
  int sum = 0;
  int squares = 0;
  int evens = 0;
  int tens = 0;
  
  cout << "Enter a low and a high value" << endl;
  cin  >> low;
  cin  >> high;
  
  if (low > high)
  {
    cout << "Woops you misunderstood what you were supposed to enter..." << endl;
    return 0;
  }
  else
  {
    cout << "Differce: " << high - low << endl;
    
    for (int i = low; i <= high; i++)
    {
      sum = sum + i;
      squares = squares + (i * i);
      
      if (i % 2 == 0)
      {
        evens++;
      }
      
      if (i % 10 == 0)
      {
        tens++;
      }
    }
    cout << "Sum: " << sum << endl;
    cout << "Sum of squares: " << squares << endl;
    cout << "Evens: " << evens << endl;
    cout << "Tens: " << tens << endl;
  }
  
  return 0;
}