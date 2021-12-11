#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <math.h>
#include <vector>
#include <assert.h>
using namespace std;

void readInFile();
void solve1(ifstream& file1);
void solve2(ifstream& file2);
void printVec(vector<vector<int>>& vec);
int isGlow(int i, int j, vector<vector<int>>& field);

int main(){
  std::ifstream file1("input.txt");
  std::ifstream file2("input.txt");
//  readInFile();
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
  string line;
  vector<vector<int>> field;
  while(getline(file, line)){
    vector<int> vec;
    for (char ch : line){
      int nr = ch - '0';
      vec.push_back(nr);
    }
    field.push_back(vec);
  }
//  printVec(field);
  long countFlash = 0;
  for (int step = 0; step < 100; step++){
    for (int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        field[i][j]++;
      }
    }
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        if (field[i][j] > 0){
          countFlash += isGlow(i, j, field);
        }
      }
    }
    cout << "step " << step << " partRes " << countFlash << endl;
    printVec(field);
    cout << endl;
  }
}
void solve2(ifstream& file){
  string line;
  vector<vector<int>> field;
  while(getline(file, line)){
    vector<int> vec;
    for (char ch : line){
      int nr = ch - '0';
      vec.push_back(nr);
    }
    field.push_back(vec);
  }
//  printVec(field);
  long countFlash = 0;
  int step = 1;
  while (true){
    for (int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        field[i][j]++;
      }
    }
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        if (field[i][j] > 0){
          countFlash += isGlow(i, j, field);
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        sum += field[i][j];
      }
    }
    if (sum == 0){
      cout << "res " << step << endl;
      break;
    }
    step++;

    cout << "step " << step << " partRes " << countFlash << endl;
    printVec(field);
    cout << endl;
  }
    printVec(field);
    cout << endl;

}
void printVec(vector<vector<int>>& vec){
  for (int i = 0; i < vec.size(); i++){
    for (int j = 0; j < vec[i].size(); j++){
      cout << vec[i][j];
    }
    cout << endl;
  }
}
int isGlow(int i, int j, vector<vector<int>>& field){
//  assert(field[i][j] < 11);
  if(field[i][j] < 10){
    return 0;
  }
  // can be 10 or 11 (because of increment)
  // glows

  field[i][j] = 0;
  int res = 1; // i, j is glowing
  if (i+1 < 10){
    if (field[i+1][j] > 0){
      field[i+1][j]++;
      res += isGlow(i+1, j, field);
    }
    if (j+1 < 10){
      if (field[i+1][j+1] > 0){
        field[i+1][j+1]++;
        res += isGlow(i+1, j+1, field);
      }
    }
    if (j-1 >= 0){
      if (field[i+1][j-1] > 0){
        field[i+1][j-1]++;
        res += isGlow(i+1, j-1, field);
      }
    }
  }
  if(i-1 >= 0){
    if (field[i-1][j] > 0){
      field[i-1][j]++;
      res += isGlow(i-1, j, field);
    }
    if (j+1 < 10){
      if (field[i-1][j+1] > 0){
        field[i-1][j+1]++;
        res += isGlow(i-1, j+1, field);
      }
    }
    if (j-1 >= 0){
      if (field[i-1][j-1] > 0){
        field[i-1][j-1]++;
        res += isGlow(i-1, j-1, field);
      }
    }
  }
  if(j+1 < 10){
    if (field[i][j+1] > 0){
      field[i][j+1]++;
      res += isGlow(i, j+1, field);
    }
  }
  if (j-1 >= 0){
    if (field[i][j-1] > 0){
      field[i][j-1]++;
      res += isGlow(i, j-1, field);
    }
  }
  return res;
}


