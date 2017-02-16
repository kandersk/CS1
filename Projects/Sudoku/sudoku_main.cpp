/*
Soduko solver for a 9*9 puzzle made in c++

Author : Kristians Kanders
         kandersk@uindy.edu

*/
#include "sfunc.h"
#include <iostream>

void printTable(cell_t a[]);
void makePuzzle(cell_t table[]);
bool goodRow (cell_t a, int pos, cell_t table[]);
bool goodCol (cell_t a, int pos, cell_t table[]);
bool goodSq  (cell_t a, int pos, cell_t table[]);
bool doesFit (cell_t a, int pos, cell_t table[]);
bool isSolved (cell_t table[]);
int findSpot (cell_t table[]);
bool solve (cell_t table[]);

int main(){
  cell_t table[81];

  makePuzzle(table);

  printTable(table);

  if (solve (table) == true){
    std::cout << "Done!" << '\n';
  }

  printTable(table);

  return 0;
}
void printTable(cell_t a[]){
  std::cout << " ╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗" << '\n';
  std::cout << "a║ "<< a[0].getVal() <<" │ "<< a[1].getVal() <<" │ "<< a[2].getVal() <<" ║ "
  << a[3].getVal() <<" │ "<< a[4].getVal() <<" │ "<< a[5].getVal() <<" ║ "<< a[6].getVal() <<" │ "
  << a[7].getVal() <<" │ "<< a[8].getVal() <<" ║" << '\n';
  std::cout << " ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << '\n';
  std::cout << "b║ "<< a[9].getVal() <<" │ "<< a[10].getVal() <<" │ "<< a[11].getVal() <<" ║ "
  << a[12].getVal() <<" │ "<< a[13].getVal() <<" │ "<< a[14].getVal() <<" ║ "<< a[15].getVal() <<" │ "
  << a[16].getVal() <<" │ "<< a[17].getVal() <<" ║" << '\n';
  std::cout << " ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << '\n';
  std::cout << "c║ "<< a[18].getVal() <<" │ "<< a[19].getVal() <<" │ "<< a[20].getVal() <<" ║ "
  << a[21].getVal() <<" │ "<< a[22].getVal() <<" │ "<< a[23].getVal() <<" ║ "<< a[24].getVal() <<" │ "
  << a[25].getVal() <<" │ "<< a[26].getVal() <<" ║" << '\n';
  std::cout << " ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣" << '\n';
  std::cout << "d║ "<< a[27].getVal() <<" │ "<< a[28].getVal() <<" │ "<< a[29].getVal() <<" ║ "
  << a[30].getVal() <<" │ "<< a[31].getVal() <<" │ "<< a[32].getVal() <<" ║ "<< a[33].getVal() <<" │ "
  << a[34].getVal() <<" │ "<< a[35].getVal() <<" ║" << '\n';
  std::cout << " ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << '\n';
  std::cout << "e║ "<< a[36].getVal() <<" │ "<< a[37].getVal() <<" │ "<< a[38].getVal() <<" ║ "
  << a[39].getVal() <<" │ "<< a[40].getVal() <<" │ "<< a[41].getVal() <<" ║ "<< a[42].getVal() <<" │ "
  << a[43].getVal() <<" │ "<< a[44].getVal() <<" ║" << '\n';
  std::cout << " ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << '\n';
  std::cout << "f║ "<< a[45].getVal() <<" │ "<< a[46].getVal() <<" │ "<< a[47].getVal() <<" ║ "
  << a[48].getVal() <<" │ "<< a[49].getVal() <<" │ "<< a[50].getVal() <<" ║ "<< a[51].getVal() <<" │ "
  << a[52].getVal() <<" │ "<< a[53].getVal() <<" ║" << '\n';
  std::cout << " ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣" << '\n';
  std::cout << "g║ "<< a[54].getVal() <<" │ "<< a[55].getVal() <<" │ "<< a[56].getVal() <<" ║ "
  << a[57].getVal() <<" │ "<< a[58].getVal() <<" │ "<< a[59].getVal() <<" ║ "<< a[60].getVal() <<" │ "
  << a[61].getVal() <<" │ "<< a[62].getVal() <<" ║" << '\n';
  std::cout << " ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << '\n';
  std::cout << "h║ "<< a[63].getVal() <<" │ "<< a[64].getVal() <<" │ "<< a[65].getVal() <<" ║ "
  << a[66].getVal() <<" │ "<< a[67].getVal() <<" │ "<< a[68].getVal() <<" ║ "<< a[69].getVal() <<" │ "
  << a[70].getVal() <<" │ "<< a[71].getVal() <<" ║" << '\n';
  std::cout << " ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢" << '\n';
  std::cout << "i║ "<< a[72].getVal() <<" │ "<< a[73].getVal() <<" │ "<< a[74].getVal() <<" ║ "
  << a[75].getVal() <<" │ "<< a[76].getVal() <<" │ "<< a[77].getVal() <<" ║ "<< a[78].getVal() <<" │ "
  << a[79].getVal() <<" │ "<< a[80].getVal() <<" ║" << '\n';
  std::cout << " ╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝" << '\n';
  std::cout << "   1   2   3   4   5   6   7   8   9 " << '\n';
}
void makePuzzle(cell_t table[]){
  table[0].setVal(5);
  table[1].setVal(3);
  table[4].setVal(7);
  table[9].setVal(6);
  table[12].setVal(1);
  table[13].setVal(9);
  table[14].setVal(5);
  table[19].setVal(9);
  table[20].setVal(8);
  table[25].setVal(6);
  table[27].setVal(8);
  table[31].setVal(6);
  table[35].setVal(3);
  table[36].setVal(4);
  table[39].setVal(8);
  table[41].setVal(3);
  table[44].setVal(1);
  table[45].setVal(7);
  table[49].setVal(2);
  table[53].setVal(6);
  table[55].setVal(6);
  table[60].setVal(2);
  table[61].setVal(8);
  table[66].setVal(4);
  table[67].setVal(1);
  table[68].setVal(9);
  table[71].setVal(5);
  table[76].setVal(8);
  table[79].setVal(7);
  table[80].setVal(9);

  table[0].setChange(false);
  table[1].setChange(false);
  table[4].setChange(false);
  table[9].setChange(false);
  table[12].setChange(false);
  table[13].setChange(false);
  table[14].setChange(false);
  table[19].setChange(false);
  table[20].setChange(false);
  table[25].setChange(false);
  table[27].setChange(false);
  table[31].setChange(false);
  table[35].setChange(false);
  table[36].setChange(false);
  table[39].setChange(false);
  table[41].setChange(false);
  table[44].setChange(false);
  table[45].setChange(false);
  table[49].setChange(false);
  table[53].setChange(false);
  table[55].setChange(false);
  table[60].setChange(false);
  table[61].setChange(false);
  table[66].setChange(false);
  table[67].setChange(false);
  table[68].setChange(false);
  table[71].setChange(false);
  table[76].setChange(false);
  table[79].setChange(false);
  table[80].setChange(false);
}

bool goodRow (cell_t a, int pos, cell_t table[]){
  //checks if the number fits in the row
  for (int i = pos - (pos % 9); i < pos - (pos % 9) + 9; i++){
    if (i != pos){
      if (table[i].getNum() == a.getNum()){
        return false;
      }
    }
  }
  return true;
}
bool goodCol (cell_t a, int pos, cell_t table[]){
  //checks if the number fits in the column
  for (int i = pos % 9; i < 81; i += 9){
    if (i != pos){
      if (table[i].getNum() == a.getNum()){
        return false;
      }
    }
  }
  return true;
}
bool goodSq (cell_t a, int pos, cell_t table[]){
  //checks if the number fits in the square 57/9 = 6 57%9 = 3
  int hor = pos % 9;
  int vert = pos / 9;
  // check which square horizontally it is (1 2 or 3)
  if (hor < 3){
    hor = 0;
  }else if (hor > 5){
    hor = 6;
  }else{
    hor = 3;//
  }
  //check which square vertically
  if (vert < 3){
    vert = 0;
  }else if (vert > 5){
    vert = 6;//
  }else{
    vert = 3;
  }
  // loop through the cells in the square
  for (int i = 9 * vert; i < 9 * vert + 18; i += 9){
    for (int b = i + hor ; b < i + hor + 3; b++){
      if (pos != b){
        if (table[b].getNum() == a.getNum()){
          return false;
        }
      }
    }
  }
  return true;
}
bool doesFit(cell_t a, int pos, cell_t table[]){
  if (a.getNum() == 0){return false;}
  if (goodRow (a, pos, table) == false){return false;}
  if (goodCol (a, pos, table) == false){return false;}
  if (goodSq  (a, pos, table) == false){return false;}
  return true;
}
bool isSolved (cell_t table[]){
  for (int i = 0; i < 81; i++){
    if (doesFit(table[i], i, table) == false){
      return false;
    }
  }
  return true;
}
int findSpot (cell_t table[]){
  for (int i = 0; i < 81; i++){
    if (table[i].getNum() == 0){
      return i;
    }
  }
  return -1;
}
bool solve (cell_t table[]){
  if (isSolved(table) == true){
    return true;
  }
  int b = findSpot(table);
  for (int i = 1; i <= 9; i++){
    if (b == -1){
      return true;
    }else{
      table[b].setVal(i);
      if (doesFit(table[b], b, table) == true){
        if (solve(table) == true){
          return true;
        }
      }
    }
  }
  table[b].setVal(0);
  return false;
}
