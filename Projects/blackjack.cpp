/*
A game of blackjack with dealer rule of hit if score is < 17, aces count as 11
each run is one play

By:
Kristians Kanders
kandersk@uindy.edu

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void shuffle (int d[], int length);
int getSuit(int card);
int getCard(int card);
int getScore(int card);
void printCard(int card);
char getChoice();
void dealerPlay(int& dealerScore, int dealer[], int& pos, int& dealerCount);
void printHands(int h[], int d[], int hCount, int dCount);

std:: string suits[] =
{"Hearts", "Spades", "Diamonds","Clubs"};
std:: string cards[] =
{"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};

int main(){
  srand(time(0));

  int deck[52];
  int hand[10] = {0};
  int dealer[10] = {0};
  int handScore = 0;
  int dealerScore = 0;
  int winner = 0;
  int playing = 0;
  int counter = 2;
  int skip = 0;
  int dealerCount = 0;
  int pos = 0;
  char choice = ' ';
  for (int i = 0; i < 52; ++i){
    deck[i] = i;

  }
  shuffle (deck, 52);
  for (int i = 0; i < 10; i++){
    hand[i] = deck[i];
    dealer[i] = deck[21 + i];
  }
  printHands(hand, dealer, 2, 1);

  handScore = getScore(hand[0]) + getScore(hand[1]);
  std::cout << "Your Score: " << handScore << '\n';

  if (handScore > 21){
    std::cout << "You Bust" << '\n';
    return 0;
  }else if (handScore == 21){
    std::cout  << '\n';
    std::cout  << '\n';
    skip = 1;
  }

  do {
    if (skip == 1 || getChoice() == 'S'){
      dealerPlay(dealerScore, dealer, pos, dealerCount);
      std::cout << "\033[10A";
      printHands(hand, dealer, counter, dealerCount);
      std::cout << "Your Score: " << handScore << "\t   ";
      std::cout << "Dealer Score: " << dealerScore << '\n';
      if (dealerScore > 21){
        std::cout << "Dealer Busts, you win!" << '\n';
        return 0;
      }
      playing = 1;
    }
    else{
      std::cout << "\033[10A";
      ++counter;
      printHands(hand, dealer, counter, 1);
      handScore += getScore(hand[counter - 1]);
      std::cout << "Your Score: " << handScore << '\n';
      if (handScore > 21){
        std::cout << "You Bust             " << '\n';
        return 0;
      }else if (handScore == 21){
        skip = 1;
      }
    }
  } while(playing == 0);

  if (dealerScore == 21 && handScore == 21){
    if (dealerCount == 2 || dealerCount == counter){
      std::cout << "You lose             " << '\n';
    }else if(dealerCount < counter){
      std::cout << "You lose             " << '\n';
    }else{
      std::cout << "You Win              " << '\n';
    }

  }else if (dealerScore == handScore){
    std::cout << "Tie                  " << '\n';
  }else if (dealerScore > handScore){
    std::cout << "You Lose             " << '\n';
  }else{
    std::cout << "You Win              " << '\n';
  }

  return 0;
}

void shuffle (int d[], int length){
  int j = 0;
  int swap = 0;
  for (int i = 51; i > 0; --i){
    j = rand() % i;
    swap = d[j];
    d[j] = d[i];
    d[i] = swap;
  }
}
int getSuit(int card){
  return card / 13;
}
int getCard (int card){
  return card % 13;
}
int getScore(int card){
  int score = getCard(card);
  if (score == 12){
    return 11;
  }else if (score > 8){
    return 10;
  }else{
    return score + 2;
  }
}
void printCard(int card){
  std::cout << cards[getCard(card)] << " Of "
  << suits[getSuit(card)];
}
char getChoice(){
  char choice = ' ';
  std::cout << "Hit (H) or Stay (S)" << '\n';
  std::cin >> choice;
  std::cout << "\033[1A" << "  " << '\n';
  if (choice == 'h' || choice == 'H'){
    return 'H';
  }
  else{
    return 'S';
  }
}
void dealerPlay(int& dealerScore, int dealer[], int& pos, int& dealerCount){
  if (dealerScore < 17){
    dealerCount++;
    dealerScore += getScore(dealer[pos]);
    //std::cout << dealerScore << " " << pos << " " << getScore(dealer[pos]) << '\n';
    pos++;
    dealerPlay(dealerScore, dealer, pos, dealerCount);
  }
  else{
    return;
  }
}
void printHands(int h[], int d[], int hCount, int dCount){
  std::cout << "You have\t\tDealer has" << '\n';
  for (int i = 0; i < hCount; i++){
    std::cout << std::left;
    printCard(h[i]);
    std::cout << '\n';
  }
  for (int i = 0; i < 6 - hCount; i++){
    std::cout << '\n';
  }
  std::cout << "\033[6A";

  for (int i = 0; i < dCount; i++){
    std::cout << "\t\t\t";
    std::cout << std::right;
    printCard(d[i]);
    std::cout << '\n';
  }
  for (int i = 0; i < 6 - dCount; i++){
    std::cout << '\n';
  }
}
