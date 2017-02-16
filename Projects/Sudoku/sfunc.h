/*
Definition of the cell class for the sudoku solver
*/
#ifndef SFUNC_H
#define SFUNC_H

#include <iostream>

class cell_t{
private:
  char val;


public:
  cell_t(); // defaults the cell as a blank ' ' character
  cell_t(char); // sets the cell to have a number,

  char getVal(); //returns char value of cell
  int getNum(); // returns integer value of cell

  void setVal(char);

};
#endif
