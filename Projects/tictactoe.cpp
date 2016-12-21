/*
An unbeatable game of tictactoe using the minimax algorithm.

Author;
Kristians Kanders
kandersk@uindy.edu
*/
#include <iostream>
#include <vector>
using namespace std;

int checkWin(char board[], int winner);
void endGame(char board[], int& turn, int& winner);
void getBestMove(char board[]);
int miniMax(char board[], int player, int depth);
int max (int current, int check);
int min (int current, int check);

int main (){
  char board [9] = {'1','2','3','4','5','6','7','8','9'};
  char oldboard [9];
  int input = 0;
  int winner = 0;
  int turn = 1;
  int player = 0;
  do{
    if (turn % 2 == 1){
      player = 1;
    }else{
      player = 2;
    }
    //cout << "Player " << player << endl;
    cout << endl << board[0] << " │ " << board[1] << " │ "
    << board[2] << "\n──┼───┼──\n" << board[3] << " │ "
    << board[4] << " │ " << board[5] << "\n──┼───┼──\n"
    << board[6] << " │ " << board[7] << " │ " << board[8]
    << endl;

    do{
      cout << "Input:  " << "\033[1D";
      cin  >> input;
    }while (input <= 1 && input >= 9);

    input = input - 1;
    board[input] = 'x';
    cout << "\033[7A";

    endGame (board, turn, winner);

    getBestMove(board);
    if (winner == 0){
      endGame (board, turn, winner);
    }
    turn++;
  }while (winner == 0);

  return 0;
}

int checkWin(char board[], int winner){
  if (board[0] == board[1] && board[0] == board[2]){
    if (board[0] == 'x'){
      winner = 2;
    }else{
      winner = 1;
    }
  }else if (board[3] == board[4] && board[3] == board[5]){
    if (board[3] == 'x'){
      winner = 2;
    }else{
      winner = 1;
    }
  }else if (board[6] == board[7] && board[6] == board[8]){
    if (board[6] == 'x'){
      winner = 2;
    }else{
      winner = 1;
    }
  }else if (board[0] == board[4] && board[0] == board[8])
  {
    if (board[0] == 'x'){
      winner = 2;
    }else{
      winner = 1;
    }
  }else if (board[2] == board[4] && board[2] == board[6]){
    if (board[2] == 'x'){
      winner = 2;
    }else{
      winner = 1;
    }
  }else if (board[1] == board[4] && board[1] == board[7]){
    if (board[1] == 'x'){
      winner = 2;
    }else{
      winner = 1;
    }
  }else if (board[0] == board[3] && board[0] == board[6]){
    if (board[0] == 'x'){
      winner = 2;
    }else{
      winner = 1;
    }
  }else if (board[2] == board[5] && board[2] == board[8]){
    if (board[2] == 'x'){
      winner = 2;
    }else{
      winner = 1;
    }
  }else if (winner == 0 && board[0] != '1' && board[1] != '2'
      && board[2] != '3' && board[3] != '4' && board[4] != '5'
      && board[5] != '6' && board[6] != '7' && board[7] != '8'
      && board[8] != '9'){
        winner = 3;
      }
  return winner;

}

void endGame (char board[], int& turn, int& winner){

  if (checkWin (board, winner) == 3){
    //cout << "\033[31m";
    cout << endl << board[0] << " │ " << board[1] << " │ "
    << board[2] << "\n──┼───┼──\n" << board[3] << " │ "
    << board[4] << " │ " << board[5] << "\n──┼───┼──\n"
    << board[6] << " │ " << board[7] << " │ " << board[8]
    << endl;
    //cout << "\033[30m";

    cout << "Oh no, everyone is a loser..." << endl;
    cout << "Sucks!" << endl;
    cout << "Game over in " << turn - 1 << " turns :/" << endl;
    winner = 1;
    return;
  }

  else if (checkWin(board, winner) == 2){
    cout << endl << board[0] << " │ " << board[1] << " │ "
    << board[2] << "\n──┼───┼──\n" << board[3] << " │ "
    << board[4] << " │ " << board[5] << "\n──┼───┼──\n"
    << board[6] << " │ " << board[7] << " │ " << board[8]
    << endl;
    //cout << "\033[32m";
    cout << "Congratulations, you win." << endl;
    //cout << "\033[30m";
    cout << "Game over in " << turn - 1 << " turns" << endl;
    winner = 1;
    return;
    }

  else if (checkWin(board, winner) == 1){
    cout << endl << board[0] << " │ " << board[1] << " │ "
    << board[2] << "\n──┼───┼──\n" << board[3] << " │ "
    << board[4] << " │ " << board[5] << "\n──┼───┼──\n"
    << board[6] << " │ " << board[7] << " │ " << board[8]
    << endl;

    //cout << "\033[31m";
    cout << "You lose!" << endl;
    //cout << "\033[30m";
    cout << "Game over in " << turn - 1 << " turns" << endl;
    winner = 1;
    return;
  }
}

void getBestMove(char board[]){
  char move = 'o';
  int bestVal = -1000;
  int bestMove = -1;

  for (int i = 0; i < 9; i++){
    if (board[i] >= '1' && board[i] <= '9'){
      board[i] = move;

      int moveVal = miniMax(board, 1, 0);

      board[i] = 49 + i;

      if (moveVal > bestVal){
        bestMove = i;
        bestVal = moveVal;
      }
    }
  }
  board[bestMove] = move;
}

int miniMax(char board[], int player, int depth){
  if (checkWin(board, 0) == 1){
    return 10 - depth;
  }
  else if (checkWin(board, 0) == 2){
    return depth - 10;
  }
  else if (checkWin(board, 0) == 3){
    return 0;
  }
  char move;
  if (player == 2){
    move = 'o';
    int best = -1000;

    for (int i = 0; i < 9; i++){
      if (board[i] >= '1' && board[i] <= '9'){
        board[i] = move;
        best = max(best, miniMax(board, 1, depth++));
        board[i] = 49 + i;
      }
    }
    return best;
  }else{
    move = 'x';
    int best = 1000;

    for (int i = 0; i < 9; i++){
      if (board[i] >= '1' && board[i] <= '9'){
        board[i] = move;
        best = min(best, miniMax(board, 2, depth++));

        board[i] = 49 + i;
      }
    }
    return best;
  }
}

int max (int current, int check){
  if (current >= check){
    return current;
  }else{
    return check;
  }
}

int min (int current, int check){
  if (current <= check){
    return current;
  }else{
    return check;
  }
}
