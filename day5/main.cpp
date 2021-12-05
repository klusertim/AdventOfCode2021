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
pair<int, int> maxim(int i, int j);

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
  vector<vector<int>> field(1000);
  for (int i = 0; i < 1000; i++){
    field[i] = vector<int>(1000, 0); // initialize with 0
  }

  // read input
  while (true){
    int x1, x2, y1, y2;
    char ch;
    file >> x1;
    file >> ch; // read ,
    file >> y1;
    for (int i = 0; i < 2; i++) file >> ch; // read ->
    file >> x2;
    file >> ch; // read , 
    file >> y2;

    if (file.eof()) break;
    
    int count = 0;
    // case distinction
    if (x1 == x2 && y1 != y2){
      pair<int, int> bounds = maxim(y1, y2);
      // cout << "big " << bounds.first << " small " << bounds.second << endl;
      for (int i = bounds.second; i <= bounds.first; i++){
        field[x1][i]++;
        count++;
      }
    }else if ((y1 == y2) && (x1 != x2)){
      pair<int, int> bounds = maxim(x1, x2);
      for (int i = bounds.second; i <= bounds.first; i++){
        field[i][y1]++;
      }
    }
    // cout << "i " << count << endl;

    // if (x1 == x2 && y1 == y2) field[x1][y1]++;

//    cout << "x1 " << x1 << " x2 " << x2 << " y1 " << y1 << " y2 " << y2 << endl;
    // read next line
    
  }
  int overlaps = 0; // overlap bigger than two
  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++){
      if (field[i][j] >= 2) overlaps++;
      //cout << field[i][j] << " ";
    }
    //cout << endl;
  }
  cout << "overlaps1 " << overlaps << endl;
}
void solve2(ifstream& file){
  vector<vector<int>> field(1000);
  for (int i = 0; i < 1000; i++){
    field[i] = vector<int>(1000, 0); // initialize with 0
  }

  // read input
  while (true){
    int x1, x2, y1, y2;
    char ch;
    file >> x1;
    file >> ch; // read ,
    file >> y1;
    for (int i = 0; i < 2; i++) file >> ch; // read ->
    file >> x2;
    file >> ch; // read , 
    file >> y2;

    if (file.eof()) break;
    
    int count = 0;
    // case distinction
    if (x1 == x2){
      pair<int, int> bounds = maxim(y1, y2);
      // cout << "big " << bounds.first << " small " << bounds.second << endl;
      for (int i = bounds.second; i <= bounds.first; i++){
        field[x1][i]++;
        count++;
      }
    }else if (y1 == y2 && x1 != x2) {
      pair<int, int> bounds = maxim(x1, x2);
      for (int i = bounds.second; i <= bounds.first; i++){
        field[i][y1]++;
      }
    }else{
      
      pair<int, int> x = maxim(x1, x2);
      pair<int, int> y = maxim(y1, y2);
      if(((x1 < x2) && (y1 < y2) ) || ((x1 > x2) && (y1 > y2))){
        for (int i = 0 ; i <= x.first - x.second ; i++){
          field[(x.second + i)][(y.second + i)]++;
        }
      }else{
        for(int i = 0; i <= x.first - x.second; i++){
          field[(x.second + i)][(y.first - i)]++;
        }
      }

    }
    //cout << "i " << count << endl;

    // cout << "x1 " << x1 << " x2 " << x2 << " y1 " << y1 << " y2 " << y2 << endl;
    
  }
  int overlaps = 0; // overlap bigger than two
  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++){
      if (field[i][j] >= 2) overlaps++;
      //cout << field[i][j] << " ";
    }
    //cout << endl;
  }
  cout << "overlaps2 " << overlaps << endl;

}

pair<int, int> maxim(int i, int j){
  if (i >= j){
    return pair<int, int>(i, j);
  }else{
    return pair<int, int>(j, i);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          }
}
