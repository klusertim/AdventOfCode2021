#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void readInFile();
void solve1(ifstream& file);
void solve2(ifstream& file);

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
  int horPos = 0;
  int depth = 0;
  string direction;
  int change;
  while (true){     
    file >> direction;
    file >> change;
    if (file.eof()) break;
   // switch(direction){ // switch case does not work on strings
   //   case "forward":
   //     horPos += change;
   //   case "down":
   //     depth += change;
   //   case "up":
   //     depth -= change;
   // }
//    cout << direction << change <<  endl;
    if(direction.compare("forward") == 0){ // are 0 if equal
      horPos += change;
    }else if(direction.compare("down") == 0 ){
      depth += change;
    }else {
      depth -= change;
    }
  }
  cout << horPos << " " << depth << endl;
  int res = horPos * depth;
  cout << "task 1: " << res << endl;
}
void solve2(ifstream& file){
  int horPos = 0;
  int depth = 0;
  int aim = 0;
  string direction;
  int change;
  while (true){     
    file >> direction;
    file >> change;
    if (file.eof()) break;
   // switch(direction){ // switch case does not work on strings
   //   case "forward":
   //     horPos += change;
   //   case "down":
   //     depth += change;
   //   case "up":
   //     depth -= change;
   // }
//    cout << direction << change <<  endl;
    if(direction.compare("forward") == 0){ // are 0 if equal
      horPos += change;
      depth += (aim * change);
    }else if(direction.compare("down") == 0 ){
      aim += change;
    }else {
      aim -= change;
    }
  }
  cout << horPos << " " << depth << endl;
  int res = horPos * depth;
  cout << "task 2: " << res << endl;

}
