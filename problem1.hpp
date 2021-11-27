#ifndef HEADER_HPP
#define HEADER_HPP
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void problem2(ifstream& file);

void problem2(ifstream& file){
    int pwdCount1 = 0; // for part 1
    int pwdCount2 = 0; // for part 2
    int nrLines = 0;
    while(true){
      //ifstream& line;
      nrLines++;
      string thisLine;
      getline(file, thisLine); // get the line of the stream 
      if (file.eof()) break;

      stringstream line(thisLine); // make a stringstream
    }
}
#endif
