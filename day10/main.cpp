#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void readInFile();
void solve1(ifstream& file1);
void solve2(ifstream& file2);
void clearAll(stack<int>& st);

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
  vector<string> lines;
  while (getline(file, line)){
    lines.push_back(line);
  }
  
  int linesSize = lines.size();
  long res = 0;
  for (int i = 0; i < linesSize; i++){
    stack<int> brackets;
    cout << "line " << lines[i] << endl;
    for (char ch : lines[i]){

//    cout << "partres " << res << endl;
//    cout << "char " << ch << " ";
      if(ch == '('){
        brackets.push(1);
        continue;
      }
      if(ch == '['){
        brackets.push(2);
        continue;
      }
      if(ch == '{'){
        brackets.push(3);
        continue;
      }
      if (ch == '<'){
        brackets.push(4);
        continue;
      }
      if (brackets.size() <= 0){
        break;
      }
      if (ch == ')'){
        if (brackets.top() != 1){
          res += 3;
          break;
        }
        brackets.pop();
        continue;
      }
      if (ch == ']'){
        if (brackets.top() != 2){
          res += 57;
          break;
        }
        brackets.pop();
        continue;
      }
      if (ch == '}'){
        if (brackets.top() != 3){
          res += 1197;
          break;
        }
        brackets.pop();
        continue;
      }
      if( ch == '>' ){
        if (brackets.top() != 4){
//          cout << " top " << brackets.top() << endl;
          res += 25137;
          break;
        }
        brackets.pop();
        continue;
      }
    }
  }
  cout << "res " << res << endl;
}
void solve2(ifstream& file){
  string line;
  vector<string> lines;
  while (getline(file, line)){
    lines.push_back(line);
  }
  
  int linesSize = lines.size();
  long res = 0;
  vector<long> resVec;
  for (int i = 0; i < linesSize; i++){
    long partRes = 0;
    stack<int> brackets;
    cout << "line " << lines[i] << endl;
    for (char ch : lines[i]){

//    cout << "partres " << res << endl;
//    cout << "char " << ch << " ";
      if(ch == '('){
        brackets.push(1);
        continue;
      }
      if(ch == '['){
        brackets.push(2);
        continue;
      }
      if(ch == '{'){
        brackets.push(3);
        continue;
      }
      if (ch == '<'){
        brackets.push(4);
        continue;
      }
      if (ch == ')'){
        if (brackets.top() != 1){
          clearAll(brackets);
          break;
        }
        brackets.pop();
        continue;
      }
      if (ch == ']'){
        if (brackets.top() != 2){
          clearAll(brackets);
          break;
        }
        brackets.pop();
        continue;
      }
      if (ch == '}'){
        if (brackets.top() != 3){
          clearAll(brackets);
          break;
        }
        brackets.pop();
        continue;
      }
      if( ch == '>' ){
        if (brackets.top() != 4){
          clearAll(brackets);
          break;
        }
        brackets.pop();
        continue;
      }
    }
    if (brackets.size() != 0){
        int stackSize = brackets.size();
        for (int i = 0; i < stackSize; i++){
          partRes *= 5;
          int closeNr = brackets.top();
          brackets.pop();
          partRes += closeNr;
        }
        resVec.push_back(partRes);
        cout << "partRes " << partRes << endl;
    }
  }
  sort(resVec.begin(), resVec.end());
  int mid = (resVec.size() / 2);
  cout << "res " << resVec[mid] << endl;

}

void clearAll(stack<int>& st){
  int size = st.size();
  for (int i = 0; i < size; i++){
    st.pop();
  }
}
