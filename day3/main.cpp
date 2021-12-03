#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <set>
#include <list>
using namespace std;

void readInFile();
void solve1(ifstream& file);
void solve2(ifstream& file);
int stringToDec(string str);

int main(){
  std::ifstream file("input.txt");
  readInFile();
  if (file.is_open()){
    //problem1(file);
    solve2(file);
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

}

void solve1(ifstream& file){
  // get size of line of the code
  string thisLine;
  getline(file, thisLine);
  int colCount = 0;
  int rowCount = 0;
  for (char& ch : thisLine){
    colCount++;
  }
  int countOnes[colCount] = {}; // all to 0
  // cout << colCount;
  while (true){
    rowCount++;
    for (int i = 0; i < colCount; i++){
      char& bit = thisLine.at(i);
      if (bit == '1'){
        countOnes[i]++;
      }
      // cout << bit ;
    }
    // cout << endl;
    // get new line
    getline(file, thisLine);
    if (file.eof()) break;
  }

  int gamma = 0; // most common
  int epsilon = 0; // least common

  int middle;
  if ((rowCount % 2 ) == 0){
    middle = rowCount/2;
  }else{
    middle = rowCount/2 + 1;
  }

  for (int i = colCount-1; i >= 0; i--){
    if (countOnes[i] >= middle){ // more ones
      gamma += (int) pow(2, colCount - i -1);
    }else{
      epsilon += (int) pow(2, colCount - i -1);
    }
  }
  int power = gamma * epsilon;
  cout << "gamma: " << gamma << " epsilon: " << epsilon << endl;
  cout << "power: " << power;
}
void solve2(ifstream& file){

  string thisLine;
  getline(file, thisLine);
  int colCount = thisLine.size();
  int rowCount = 0;
  list<string> generator;
  list<string> scrubber;
  // cout << colCount;
  while (true){
    rowCount++;
    // cout << val << endl;
    generator.push_back(thisLine);
    scrubber.push_back(thisLine);
    getline(file, thisLine);
    if (file.eof()) break;
  }

  list<string> newGenerator;
  list<string> newScrubber;

  for (int i = 0; i < colCount; i++){
    int countOne = 0;
    for (string str : generator){
      if (str.at(i) == '1') countOne++;
    }
    // cout << "countOne" << countOne << " " << generator.size() << endl;
    char currChar = '0';
    if (countOne >= (int)(((generator.size()-1)/ 2) + 1)){
      currChar = '1';
    }
    for (string str : generator){
      if (str.at(i) == currChar){
        newGenerator.push_back(str);
    //    cout << str << endl;
      }
    }
    // cout << endl;
    list<string> newList(newGenerator);
    generator = newList;
    newGenerator.clear();
    if (generator.size() <= 1) break;
  }
  for (int i = 0; i < colCount; i++){
    int countOne = 0;
    for (string str : scrubber){
      if (str.at(i) == '1') countOne++;
    }
    // cout << "countOne" << countOne << " " << scrubber.size() << endl;
    char currChar = '1';
    if (countOne >= (int)(((scrubber.size()-1)/ 2) + 1)){
      currChar = '0';
    }
    for (string str : scrubber){
      if (str.at(i) == currChar){
        newScrubber.push_back(str);
       // cout << str << endl;
      }
    }
    // cout << endl;
    list<string> newList(newScrubber);
    scrubber = newList;
    newScrubber.clear();
    if (scrubber.size() <= 1) break;
  }

  int resGen = stringToDec(generator.front());
  int resScrub = stringToDec(scrubber.front());
  cout << "generator " << resGen << " " << generator.front() << endl;
  cout << "scrubber " << resScrub << endl;
  cout << "res " << resGen * resScrub << endl;

}

int stringToDec(string str){
  int val = 0;
  int stringLen = str.length();
  for (int i = stringLen-1; i >= 0; i--){
    if (str.at(i) == '1'){
      val += pow(2, stringLen-1-i);
    }
  }
  return val;
}
