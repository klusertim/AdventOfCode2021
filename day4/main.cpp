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
bool verify(int i, int j, vector<vector<int>>& thisboard);
pair <int, int> play(vector<int>& draws, int boardcount, vector<vector<vector<int>>>& game);

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

void solve1(ifstream& file1){
  vector<int> draws;
  string line;
  getline(file1, line);
  istringstream linestream(line);
  int thisdraw;
  while (linestream >> thisdraw){
    draws.push_back(thisdraw);
    char ch;
    linestream >> ch;
  }
  vector<vector<vector<int>>> game;
  int boardcount = 0;
  while(true){
    // input the grids
    if (file1.eof()) break;
    vector<vector<int>> col;
    for (int i = 0; i < 5; i++){
      vector<int> row;
      for (int j = 0; j < 5; j++){
        int nr;
        file1 >> nr;
        if (file1.eof()) break;
        row.push_back(nr);
      }
      if (file1.eof()) break;
      col.push_back(row);
    }
    game.push_back(col);
    boardcount++;
  }
  cout << "boardcount " << boardcount << endl;
  boardcount--;
  for (int i = 0; i < boardcount; i++){
    for (int j = 0; j < 5; j++){
      for (int k = 0; k < 5; k++){
        cout << game[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  cout << "draws: ";
  for (int i = 0; i < draws.size(); i++){
    cout << draws[i];
  }
  cout << endl;
  pair<int, int> winnerPair = play(draws, boardcount, game);
  
  cout << "was here " << endl;

  // winner sum
  int winnersum = 0;
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      if(game[winnerPair.first][i][j] != -1){
        winnersum += game[winnerPair.first][i][j];
      }
    }
  }
  int winnerDraw = draws[winnerPair.second];
  cout << " winnersum " << winnersum << endl;
  cout << "last drawn " << winnerDraw << endl;
  cout << " res " << winnersum * winnerDraw << endl;
}
pair <int, int> play(vector<int>& draws, int boardcount, vector<vector<vector<int>>>& game){
  int nrWinners = 0;
  vector<bool> win(boardcount);
  for (int i = 0; i < boardcount; i++){
    win[i] = false;
  }
  for (int draw = 0; draw < draws.size(); draw++){
    for(int board = 0; board < boardcount; board++){
      for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
          if (game[board][i][j] == draws[draw]){
            game[board][i][j] = -1;
            //cout << " before verifying " << endl;
            if (verify(i, j, game[board])){
              if (!win[board]){
                win[board] = true;
                nrWinners++;
                if (nrWinners == boardcount){
                  pair <int, int> res (board, draw);
                  return res;
                }
              }
            }
          }
        }
      }
    }
  }
  //cout << "This shouldn't happen" << endl;
  pair<int, int> error (-1, -1);
  return error;
}
bool verify( int i, int j, vector<vector<int>>& thisboard){
  //cout << "The number was changed " << thisboard[i][j] << endl;

  //  for (int j = 0; j < 5; j++){
  //    for (int k = 0; k < 5; k++){
  //      cout << thisboard[j][k] << " ";
  //    }
  //    cout << endl;
  //  }
  //  cout << endl;
  // col
  int wincount = 0;
  for (int k = 0; k < 5; k++){
    if (thisboard[i][k] == -1) wincount++;
  }
  if (wincount == 5) return true;
  // row
  wincount = 0;
  for (int k = 0; k < 5; k++){
    if (thisboard[k][j] == -1) wincount++;
  }
  if (wincount == 5) return true;
  return false;

}
void solve2(ifstream& file2){

}
