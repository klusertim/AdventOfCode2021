#ifndef HEADER_HPP
#define HEADER_HPP
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void problem1(ifstream& file);

void problem1(ifstream& file){
  // for task 1
  int nrIncreases1 = 0;
  int currNr;
  int lastNr;

  // first two numbers
  if (!file.eof()){
    file >> lastNr;
  }
  if (!file.eof()){
    file >> currNr;
  }

  while(true){
    //ifstream& line;
    if (lastNr < currNr) nrIncreases1++;
    if (file.eof()) break;
    lastNr = currNr;
    file >> currNr;
  }
  cout << "Task1: " << nrIncreases1 << endl;
  
  // for task 2: the sum is bigger if the measurement + 3 is bigger
  int nrIncreases2 = 0;
  int measArr[4];
  
  ifstream file2("input.txt");
  if (!file2.is_open()) cout << "couldn't open file " << endl;
  for (int i = 0; i < 4; i++){
    if (file2.eof()) break;
    file2 >> measArr[i];
  }
  int firstElement = 0; // make calculations modulo
  int lastElement = 3;
  while(true){
    if (measArr[(firstElement % 4)] < measArr[(lastElement % 4)]) nrIncreases2++;
    if (file2.eof()) break;
    file2 >> measArr[firstElement % 4];
    firstElement++;
    lastElement++;
  }
  cout << "Task2: " << nrIncreases2 << endl;
}
#endif
