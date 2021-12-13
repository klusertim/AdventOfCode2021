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
bool stringCont(string str, char ch);
int maxDiff(int left, int mid, int right);

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
  int maxX = 0;
  int maxY = 0;
  string line;
  // find max
  while(getline(file, line)){
    if (!stringCont(line, ',')) break;
    istringstream lineStr(line);
    int x;
    int y;
    lineStr >> x;
    char ch;
    lineStr >> ch; // read , 
    lineStr >> y;
    if (x > maxX) maxX = x;
    if (y > maxY) maxY = y;
  }
  file.seekg(0, ios::beg);
  vector<vector<int>> field(maxX+1, vector<int>(maxY+1, 0));
  while(getline(file, line)){
    if (!stringCont(line, ',')) break;
    istringstream lineStr(line);
    int x;
    int y;
    lineStr >> x;
    char ch;
    lineStr >> ch; // read , 
    lineStr >> y;
    field[x][y] = 1;
  }

  cout << "maxX" << maxX << endl;
  cout << "maxY " << maxY << endl;
//  for (int i = 0; i <= maxX; i++){
//    for (int j = 0; j <= maxY; j++){
//      cout << field[i][j] << " ";
//    }
//    cout << endl;
//  }
//  getline(file, line); // skip blank line -> don't need this
  while (getline(file, line)){
    istringstream lineStr(line);
    cout << line << endl;
    string str;
    lineStr >> str;
    lineStr >> str;
    cout << str << endl; //should be along
    char dir;
    lineStr >> dir; // x or y
    char eq;
    lineStr >> eq;
    int mid;
    lineStr >> mid;
    cout << "mid " << mid << endl;
    if (dir == 'x'){

      int maxDiffX = maxDiff(0, mid, maxX);
      cout << "maxDiff " << maxDiffX << endl;
      vector<vector<int>> newField(maxDiffX, vector<int>(maxY+1, 0));
      for (int i = 0; i <= maxDiffX; i++){
        for (int j = 0; j <= maxY; j++){
          if (mid - i -1 >= 0){
            if(field[mid -i-1][j] == 1){
              newField[maxDiffX - i - 1][j] = 1;
            }
          }
          if(mid + i + 1 <= maxX){
            if(field[mid + i + 1][j] == 1){
              newField[maxDiffX - i - 1][j] = 1;
            }
          }
        }
      }
      maxX = maxDiffX-1;
      field = newField;
    }
    if (dir == 'y'){
      int maxDiffY = maxDiff(0, mid, maxY);
      cout << "maxDiff " << maxDiffY << endl;
      vector<vector<int>> newField(maxX+1, vector<int>(maxDiffY, 0));
      for (int i = 0; i <= maxX; i++){
        for (int j = 0; j <= maxDiffY; j++){
          if (mid - j -1 >= 0){
            if(field[i][mid -j-1] == 1){
              newField[i][maxDiffY - j - 1] = 1;
            }
          }
          if(mid + j + 1 <= maxY){
            if(field[i][mid + j + 1] == 1){
              newField[i][maxDiffY - j - 1] = 1;
            }
          }
        }
      }
      maxY = maxDiffY-1;
      field = newField;

    }
    
  }
  int countOnes = 0;
  cout << "was here " << endl;
  vector<vector<char>> charField(maxX+1, vector<char>(maxY+1, ' '));
  for (int i = 0; i <= maxX; i++){
    for (int j = 0; j <= maxY; j++){
      if (field[i][j] == 1){
        countOnes++;
        charField[i][j] = '#';
      } 
      cout << charField[i][j] << " ";
    }
    cout << endl;
  }
  cout << countOnes << endl;
  
  

}
void solve2(ifstream& file){

}
int maxDiff(int left, int mid, int right){
  if(mid - left > right - mid){
    return mid-left;
  }else{
    return right-mid;
  }
}
bool stringCont(string str, char ch){
  for (char x : str){
    if (x == ch) return true;
  }
  return false;
}
