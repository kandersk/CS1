/*
Function definitions of the sudoku class
*/
#include "sfunc.h"
#include <iostream>


cell_t::cell_t(){
  val = ' ';
}
cell_t::cell_t(char a){
  val = a;
}
char cell_t::getVal(){
  return val;
}
int cell_t::getNum(){
  if (val == ' '){
    return 0;
  }
  return val - 48;
}

void cell_t:: setVal(char a){
  if(a == 0){
    val = ' ';
  }else{
    val = a + 48;
  }
}
