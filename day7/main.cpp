#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

void readInFile();
void solve1(ifstream& file1);
void solve2(ifstream& file2);

int main(){
  std::ifstream file1("input.txt");
  std::ifstream file2("input.txt");
  //readInFile();
  if (file1.is_open() && file2.is_open()){
    //problem1(file);
    solve1(file1);
    solve2(file2);
  }else{
    cout << "unable to open file";
  }
  file1.close();
  file2.close();
  return 0;
}

void readInFile(){
  // freopen("input.txt", "r", stdin); // reads the textfile to the input
  freopen("output.txt", "w", stdout); // writes the output to the output file
  freopen("error.txt", "w", stderr); // error

}

void solve1(ifstream& file){
  vector<int> input;
  int nr;
  char ch;
  int max = 0; 
  int min = 0;
  while(file >> nr){
    input.push_back(nr);
    file >> ch;
    if (nr > max){
      max = nr;
    }
    if (nr < min){
      min = nr;
    }
  }

  int size = input.size();
  
  for (int i = 0; i < size; i++){
    cout << input[i] << " ";
  }
  cout << endl;
  long minDiff = 0;
  for (int i = min; i <= max; i++){
    long currDiff = 0;
    for (int j = 0; j < size; j++){
      currDiff += abs((i-input[j]));
    }
    if (i == min) minDiff = currDiff;
    else if(currDiff < minDiff) minDiff = currDiff;
//    cout << "currDiff " << currDiff << endl;
  }
  cout << "res " << minDiff << endl;

 // int sum = 0;
 // for (int i = 0; i < input.size(); i++){
 //   sum += input[i];
 // }
 // cout << " durchsch " << (sum / input.size()) << endl;
}
void solve2(ifstream& file){

  vector<int> input;
  int nr;
  char ch;
  int max = 0; 
  int min = 0;
  while(file >> nr){
    input.push_back(nr);
    file >> ch;
    if (nr > max){
      max = nr;
    }
    if (nr < min){
      min = nr;
    }
  }

  int size = input.size();
  
  for (int i = 0; i < size; i++){
    cout << input[i] << " ";
  }
  cout << endl;
  long minDiff = 0;
  for (int i = min; i <= max; i++){
    long currDiff = 0;
    for (int j = 0; j < size; j++){
      int absdiff = abs((i-input[j]));
      int crabdiff = (absdiff * (absdiff + 1))/2;
      currDiff += crabdiff;
    }
    if (i == min) minDiff = currDiff;
    else if(currDiff < minDiff) minDiff = currDiff;
    cout << "currDiff " << currDiff << endl;
  }
  cout << "res 2 " << minDiff << endl;
}
