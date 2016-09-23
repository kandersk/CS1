/*
Program that displays a shape based on which one the user chose (from 1 to 10)
and depending on the shape can ask for the size or height and width of the shape.

Kristians Kanders
kandersk@uindy.edu
*/

#include <iostream>
#include <iomanip>

using namespace std;

int line ()
{
  int width = 0;
  cout << "Enter width: ";
  cin  >> width;
  for (int i = 1; i <= width; i++)
  {
    cout << '*';
  }
  cout << "\n";
  
  return 0;
}

int sos ()
{
  int times = 0;
  cout << "Number of calls: ";
  cin  >> times;
  
  for (int i = 1; i <= times; i++)
  {
    cout << "...---... ";
  }
  cout << "\n";
  
  return 0;
}

int square ()
{
  int size = 0;
  cout << "Enter size: ";
  cin  >> size;
  
  for (int i = 1; i <= size; i++)
  {
    for (int l = 1; l <= size; l++)
    {
      cout << '*';
    }
    cout << "\n";
  }
  return 0;
}

int rectangle ()
{
  int width = 0;
  int height = 0;
  
  cout << "Enter width: ";
  cin  >> width;
  
  cout << "Enter height: ";
  cin  >> height;
  
  for (int i = 1; i <= height; i++)
  {
    for (int w = 1; w <= width; w++)
    {
      cout << '*';
    }
    cout << "\n";
  }
  return 0;
}

int starframe ()
{
  int width = 0;
  int height = 0;
  
  cout << "Enter width: ";
  cin  >> width;
  
  cout << "Enter height: ";
  cin  >> height;
  
  for (int h = 1; h <= height; h++)
  {
    for (int w = 1; w <= width; w++)
    {
      if (h == 1 || h == height || w == 1 || w == width)
      {
        cout << '*';
      }
      else
      {
        cout << ' ';
      }
    }
    cout << "\n";
  }
  
  return 0;
}

int cornered ()
{
  int width = 0;
  int height = 0;
  
  cout << "Enter width: ";
  cin  >> width;
  
  cout << "Enter height: ";
  cin  >> height;
  
  for (int h = 1; h <= height; h++)
  {
    for (int w = 1; w <= width; w++)
    {
      if (w == 1 || w == width)
      {
        if (h == 1 || h == height)
        {
          cout << '+';
        }
        else
        {
          cout << '|';
        }
      }
      else
      {
        if (h == 1 || h == height)
        {
          cout << '-';
        }
        else
        {
          cout << ' ';
        }
      }
    }
    
    cout << "\n";
  }
  
  return 0;
}

int halfnhalf ()
{
  int width = 0;
  int height = 0;
  
  cout << "Enter width: ";
  cin  >> width;
  cout << "Enter height: ";
  cin  >> height;
  
  for (int h = 1; h <= height; h++)
  {
    for (int w = 1; w <= width; w++)
    {
      if (w == 1 || w == width)
      {
        cout << '*';
      }
      else
      {
        if (h == 1 || h == height)
        {
          cout << '*';
        }
        else
        {
          if (h % 2 == 0)
          {
            cout << "* ";
            w++;
          }
          else
          {
            cout << " *";
            w++;
          }
        }
      }
    }
    cout << "\n";
  }
  
  return 0;
}

int lowerleft ()
{
  int height = 0;
  int stars = 0;
  int spaces = 0;
  int lineLength = 0;
  
  cout << "Enter height: ";
  cin  >> height;
  
  for (lineLength = 1; lineLength <= height; lineLength++)
  {
    for (stars = 1; stars <= lineLength; stars++)
    {
      cout << "*";
    }
    for ( spaces = 1; spaces <= height - lineLength; spaces++)
    {
      cout << " ";
    }
    
    cout << "\n";
  }
  
  return 0;
}

int upperleft ()
{
  int height = 0;
    
  cout << "Enter height: ";
  cin  >> height;
 
  for(int y = 0; y < height; y++)
  {
    for (int x = height - y; x > 0; x--)
    {
      cout << "*";
    }
    cout << "\n";
  }
  
  return 0;
}

int numbers ()
{
  for (int y = 1; y <= 10; y++)
  {
    for (int x = 1; x <= 10; x++)
    {
      cout << setw(4) << x * y;
    }
    cout << "\n";
  }
  return 0;
}
  
int main ()
{
  int make = 0;
  
  cout << "Welcome to the shape maker of awesomeness! What can I do for ya'!" << endl;
  cout << "1.  Horizontal line" << endl;
  cout << "2.  SOS Calls" << endl;
  cout << "3.  Filled in square" << endl;
  cout << "4.  Filled in rectangle" << endl;
  cout << "5.  Rectangle frame made of '*'" << endl;
  cout << "6.  Rectangle of lines" << endl;
  cout << "7.  Half filled in rectangle" << endl;
  cout << "8.  Right triangle with lower left filed in" << endl;
  cout << "9.  Right triangle with upper left filled in" << endl;
  cout << "10. 10X10 multiplication table" << endl;
  cout << "Which shape should I draw: ";
  cin  >> make;
  
  if (make == 1)
  {
    line();
  }
  else if (make == 2)
  {
    sos();
  }
  else if (make == 3)
  {
    square();
  }
  else if (make == 4)
  {
    rectangle();
  }
  else if (make == 5)
  {
    starframe();
  }
  else if (make == 6)
  {
    cornered();
  }
  else if (make == 7)
  {
    halfnhalf();
  }
  else if (make == 8)
  {
    lowerleft();
  }
  else if (make == 9)
  {
    upperleft();
  }
  else if (make == 10)
  {
    numbers();
  }
  else
  {
    cout << "Bruh, you need to enter a number from 1 to 10" << endl;
    return 0;
  }
  return 0;
}