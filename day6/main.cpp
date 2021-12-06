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
  list<int> fish;
  int nr;
  char ch;
  while(file >> nr){
    file >> ch;
    fish.push_back(nr);
  }
  list<int>::iterator it;
  for (it = fish.begin(); it != fish.end(); it++){
    cout << *it << " ";
  }
  cout << endl;
  for (int i = 0; i < 80; i++){
    int nrAdd = 0; 
    for (auto itL = fish.begin(); itL != fish.end(); itL++){
      int curr = *itL;
      if (curr == 0){
        nrAdd++;
        *itL = 6;
      }else{
        *itL = curr -1;
      }
   }
    //cout << nrAdd << endl;
    for (int j = 0; j < nrAdd; j++){
      fish.push_front(8);
    }
  }
  cout << "res " << fish.size() << endl;
}
void solve2(ifstream& file){
  int nr;
  char ch;
  vector<long> count(9, 0);
  while(file >> nr){
    file >> ch;
    count[nr]++;
    cout << nr << " ";
  }
  cout << endl;
  
  for (int i = 0; i < 256; i++){
    long zero = count[0];
    for (int j = 0; j < 8; j++){
      count[j] = count[(j+1)];
    }
    count[8] = zero;
    count[6] += zero;
  }

  long res = 0;
  for (int i = 0; i < 9; i++){
    res += count[i];
  }
  cout << "res " << res << endl;

}
