/*
This is a simple text adventure game with multiple
strings, integers, scopes and if statements. Every outcome is possible.

Kristians Kanders
kandersk@uindy.edu
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int flashlight = 100;
int lever = 0;
int battery ()
{
  srand (time(0));
  if (rand() % 2 == 0)
  {
    flashlight = flashlight - 10;
    cout << "Flashlight battery: " << flashlight << "%" << endl;
  }

  return 0;
}
int pull ()
{
  srand(time(0));
  cout << "You pulled lever " << rand() % 6 + 1 << endl;
  
  return 0;
}
int main ()
{
  string name = "";
  string monster = "";
  string alice = ""; 
  char ready;
  int finale = 0;
  cout << "Hello to start off enter your name: ";
  getline (cin, name);
  cout << "Nice to meet you, " << name << endl;
  
  cout << "Totally random question... What's your favourite food? (Singular)" << endl;
  getline (cin, monster);
  
  cout << "Do you want to save the world today? (Y/N)" << endl;
  cin  >> ready;
  if (ready == 'y' || ready == 'Y')
  {
    cout << "Awesome, the world needs a hero right now!" << endl;
  }
  else
  {
    cout << "That's a shame, the world blows up as you sit and do nothing..." << endl;
    cout << "Game over" << endl;

    return 1;  
    
  }
  cout << "Well " << name << " the situation is that the evil" << endl;
  cout << monster << " monster has set a bomb that will destroy everything that is not" << endl;
  cout << monster << " in the WHOLE UNIVERSE!"<< endl;
  cout << "Are you still willing to take on the evil " << monster << " monster? (Y/N)" << endl;
  
  cin >> ready;
  if (ready == 'y' || ready == 'Y')
  {
    cout << "That's good, because you are the only one who can save the world!" << endl;
  }
  else
  {
    cout << "Gee thanks... Well I guess we are all going to die because of you" << endl;
    cout << "Game over" << endl;
    
    return 1;
  }
  
  cout << "So the " << monster << " monster agreed to only talk to whoever can answer this question..." << endl;
  cout << "And everyone was asleep at class when the teacher covered it..."<< endl; 
  cout << "We would have gone to your instructor but he is nowhere to be found" << endl;
  cout << "so you are the only hope!" << endl;
  
  cout << "The question concerns scopes... I hope you remember that stuff" << endl;
  cout << "Because the mighty " << monster << " wants to talk to you right now!" << endl;
  
  cout << "* A magical portal opens *" << endl;
  
  cout << "Do you enter the portal (Y/N)" << endl;
  cin  >> ready;
  if (ready == 'y' || ready == 'Y')
  {
    cout << "The world cheers for you as you enter this random portal thing" << endl;
    
  }
  else
  {
    cout << "You chicken out and the world is destroyed..." << endl;
    cout << "Game over" << endl;
    
    return 1;
  }
  
  cout << "You are teleported into a completely dark room and you start hearing a deep dark voice" << endl;
  cout << monster << ": Welcome to my maze... If you can answer my question right you will get a flashlight" << endl;
  cout << "But if you answer wrong you will have to walk through the maze in the dark!" << endl;
  
  cout << "In the scopes example in class what was the second string the program printed out?" << endl;
  cin  >> alice;
  
  if (alice == "Alice")
  {
    cout << monster << ": Congrats, " << name << " you can get your flashlight now" << endl;
    cout << "You obtained a flashlight" << endl;
  }
  else
  {
    cout << monster << ": Good luck finding your way" << endl;
    cout << "You start walking straight and fall in a hole to your death" << endl;
    cout << "Game over" << endl;
    return 1;
  }
  
  cout << "Flashlight battery: " << flashlight << "%" << endl;
  cout << "As soon as you turn on the flashlight you realize that you are on a very narrow bridge" << endl;
  cout << "You navigate towards the open door at the end of the bridge and you find yourself in a room of levers" << endl;
  battery();

  cout << "As you are examining the levers you accidentally drop your flashlight" << endl;
  cout << "Flashlight battery: " << flashlight / 2 << "%" << endl;
  
  cout << "Do you want to just wing it and pull a random lever? (Y/N)" << endl;
  cin  >> ready;
  
  if (ready == 'y' || ready == 'Y')
  {
    cout << "While trying not to think if that was a dumb idea you pull a lever at random" << endl;
    pull();
  }
  else
  {
    cout << "You stand there for 10 minutes and nothing happens..." << endl;
    cout << "Flashlight battery: " << flashlight - 20 << "%" << endl;
    
    cout << monster << ": Are you gonna sit there forever or are you going to come and face me?" << endl;
    cout << "You realize that you are gonna need to pull a lever so you just close your eyes and go for it..." << endl;
    pull();
  }
  
  cout << "You are suddenly teleported into another room and there he is..." << endl;
  cout << monster << ": MUAHAHAH YOU HAVE FINALLY FOUND ME, BUT IT WAS ALL FOR NOTHING" << endl;
  cout << monster << ": YOU SEE THE ONLY WAY TO STOP THE BOMB IS TO DESTROY ME AND I AM INVINCIBLE" << endl;
  cout << monster << ": MUAHHAHAHAHAHAHHAHAHAAHAHAAAAA" << endl;
  
  cout << "You sudenly remember that " << monster << "s have a weakness..." << endl;
  cout << "BATTERIES" << endl;
  
  cout << "You have two options:" << endl;
  cout << "1) Throw the battery from the flashlight at " << monster << endl; 
  cout << "2) Run at " << monster << " and stab him with the battery" << endl;
  cout << "3) Do nothing" << endl;
  cin  >> finale;
  
  if (finale == 2)
  {
    cout << "You start sprinting at the monster, but you trip and fall accidentally swallowing the battery" << endl;
    cout << "You choke to death from the battery" << endl;
    cout << "Game over" << endl;
    return 1;
  }
  else if (finale == 1)
  {
    cout << "With all your might you throw the battery at the monster and manage to hit him" << endl;
    cout << "But nothing happens..." << endl;
    cout << monster << ": You fool that is just a common misconseption!" << endl;
    cout << "The monster starts transforming into something..." << endl;
  }
  else
  {
    cout << "You just awkwardly stand there for a bit" << endl;
    cout << "Suddenly the monster starts transforming..." << endl;
  }
  
  cout << "It transforms into your teacher" << endl;
  cout << "Teacher: Hello, " << name << ", it was me all along." << endl;
  cout << "Teacher: And this whole thing was just a test for you and you passed, congrats" << endl;
  cout << "Teacher: Glad you did not try to run at me and stab me with the battery, that would have been dumb" << endl;
  cout << "The teacher teleports you home and everything goes back to normal" << endl;
  cout << "Congrats you won!!!" << endl;
    
  return 0;
}