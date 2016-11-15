#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string suits[] = {"Hearts", "Spades", "Diamonds","Clubs"};
string cards[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
void shuffle(int d[], int length);
int getSuit(int card);
int getValue(int card);
int getCombo (int hand[]);
int getWinner (int hand1[], int hand2);

int main(){
  srand(time(0));
  int deck[52];
  int player1[5] = {0,1,2,3,4};
  int player2[5] = {12,11,10,9,8};
  int simCount = 0;
  int player1stat = 0;
  int player2stat = 0;
  int player1Score = 0;
  int player2Score = 0;
  int draws = 0;
  int highCount = 0;
  int straightCount = 0;
  int flushCount = 0;
  int straightFcount = 0;
  int royalFcount = 0;
  int max = 0;
  int strength = 0;
  int strengthCount = 0;


  cout << "How many simulations to run: ";
  cin  >> simCount;

  for (int i = 0; i < 52; ++i){
    deck[i] = i;
  }
  for (int sim = 0; sim < simCount; ++sim){
    shuffle(deck, 52);
    for (int i = 0; i < 5; i++) {
      player1[i] = deck[i];
      player2[i] = deck[i + 5];
    }

    player1Score = getCombo(player1);
    player2Score = getCombo(player2);

    if(player1Score == 0){
      highCount++;
      max = player1[0];
      for (int i = 0; i < 5; ++i){
        if (player1[i] > max){
          max = player1[i];
        }
      }
      player1Score = max;
    }
    if(player2Score == 0){
      highCount++;
      max = player2[0];
      for (int i = 0; i < 5; ++i){
        if (player2[i] > max){
          max = player2[i];
        }
      }
      player2Score = max;
    }


    if (player1Score > player2Score ){
      if (player1Score < 100){
        strength += player1Score + 2;
        strengthCount ++;
      }
      player1stat ++;
    }else if (player2Score > player1Score){
      if (player2Score < 100){
        strength += player2Score + 2;
        strengthCount ++;
      }
      player2stat ++;
    }else{
      draws++;
    }

    if (player1Score == 102 ){
      straightCount++;
    }else if (player1Score == 103){
      flushCount++;
    }else if (player1Score == 104){
      straightFcount++;
    }else if (player1Score == 105){
      royalFcount++;
    }

    if (player2Score == 102){
      straightCount++;
    }else if(player2Score == 103){
      flushCount++;
    }else if (player2Score == 104){
      straightFcount++;
    }else if (player2Score == 105){
      royalFcount++;
    }
  }
  cout << "       Hand 1 won: " << (float) player1stat / (float) simCount
  * 100.0 << '%' << endl;
  cout << "       Hand 2 won: " << (float) player2stat / (float) simCount
  * 100.0 << '%' << endl;
  cout << "             Draw: " << (float) draws / (float) simCount
  * 100.0 << '%' << endl;
  cout << "Average high card: " <<
  cards[getValue(((float)strength / ((float)strengthCount)))]
  << endl;
  cout << "         Straight: " << (float) straightCount / ((float) simCount
  * 2.0) * 100.0 << '%' << endl;
  cout << "            Flush: " << (float) flushCount / ((float) simCount
  * 2.0) * 100.0 << '%' << endl;
  cout << "   Straight Flush: " << (float) straightFcount / ((float) simCount
  * 2.0) * 100.0 << '%' <<  endl;
  cout << "      Royal Flush: " << (float) royalFcount / ((float) simCount
  * 2.0) * 100.0 << '%' << endl;
  return 0;
}

void shuffle (int d[], int length){
  int temp;
  int changer = 0;
  for (int b = 0; b < 40; ++b){
    for (int i = 0; i < length; ++i){
      changer = rand() % length;
      temp = d[i];
      d[i] = d[changer];
      d[changer] = temp;
    }
  }
}

int getSuit(int card){
  return card / 13;
}
int getValue (int card){
  return card % 13;
}
int getCombo (int hand[]){
  int royalF = 0;
  int straightF = 0;
  int flush = 0;
  int straight = 0;
  int dupes = 0;

  for (int i = 0; i < 5; i++) {
    if(getValue(hand[i]) == 12){
      royalF ++;
    }
    for (int b = 0; b < 5; b++){ //3 4 1 2 2 ..... 12345 ....
      if (getValue(hand[b]) - getValue(hand[i]) == 1){
        straight++;
      }
      if (getValue(hand[i]) == getValue(hand[b])){
        dupes++;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    if (getSuit(hand[i]) == getSuit(hand[i + 1])){
      flush++;
    }
  }
  if (royalF == 1 && flush == 4 && straight == 4){
    return 105;
  }else if (straight == 4 && flush == 4){
    return 104;
  }else if (flush == 4){
    return 103;
  }else if(straight == 4 && dupes == 5){
    return 102;
  }else {
    return 0;
  }
}
