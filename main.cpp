#include <stdio.h>
#include <iostream>
#include <fstream>
#include "problem1.hpp"
// #include "problem1.hpp" würde funktionieren, da wir #ifndef header #define header im anderen file geschrieben haben
void readInFile();


int main(){
  std::ifstream file("input.txt");
  readInFile();
  if (file.is_open()){
    //problem1(file);
    problem1(file);
  }else{
    cout << "unable to open file";
  }
  file.close();
  return 0;
}

void readInFile(){
  // freopen("input.txt", "r", stdin); // reads the textfile to the input
  freopen("output.txt", "w", stdout); // writes the output to the output file
  freopen("error.txt", "w", stderr); // error

 // int a, b;
 // std::cin >> a;
 // std::cin >> b;
 // std::cout << a+b << std::endl;
 // std::cout << "This is written to the output file" << std::endl;
}
