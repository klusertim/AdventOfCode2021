#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

void readInFile();
void solve1(ifstream& file1);
void solve2(ifstream& file2);

int main(){
  std::ifstream file1("input.txt");
  std::ifstream file2("input.txt");
//  readInFile();
  if (file1.is_open() && file2.is_open()){
    //problem1(file);
//    solve1(file1);
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
  string start;
  file >> start;
  vector<char> polymer(start.length());
  for (int i = 0; i < start.length(); i++){
    polymer[i] = start.at(i);
    cout << polymer[i] << " ";
  }
  cout << endl;
 
  //read two empty lines
  getline(file, line);
  getline(file, line);

  // read rules
  map<string, char> rules;
  while(getline(file, line)){
    istringstream linestream(line);
    char ch1;
    char ch2;
    string leftRule;
    linestream >> ch1;
    linestream >> ch2;
    leftRule += ch1;
    leftRule += ch2;
    
    // read -> 
    char ch;
    linestream >> ch;
    linestream >> ch;

    char rightRule;
    linestream >> rightRule;

    rules[leftRule] = rightRule;

//    cout << leftRule << " -> " << rightRule << endl;
  }

  
  for (int i = 0; i < 10; i++){
    cout << "step " << i+1 << endl;
    int newLength = 2 * polymer.size() -1;
    vector<char> newPolymer(newLength);
    newPolymer[0] = polymer[0]; // insert first element
    for (int j = 1; j < polymer.size(); j++){
      char ch1 = polymer[j-1];
      char ch2 = polymer[j];
      string leftRule;
      leftRule += ch1;
      leftRule += ch2;
//      cout << "leftRule " << leftRule << endl;
      auto find = rules.find(leftRule);
      char ch3 = find->second;
//      cout << "rightRule " << ch3 << endl;
      int index = 2 * (j);
      newPolymer[index - 1] = ch3;
      newPolymer[index] = ch2;
    }
    polymer = newPolymer;
//    for (int i = 0; i < polymer.size(); i++){
//      cout << polymer[i] << " ";
//    }
//    cout << endl;
  }
  
  int countLength = ((int)'Z'-'A')+1;
  vector<long> count(countLength, 0); // A is 0, Z = 'Z'-'A'

  for (int i = 0; i < polymer.size(); i++){
    int index = (int)polymer[i]-'A';
    count[index]++;
//    cout << "was here " << endl;
  }
  long max = 0;
  long min = 0;

  vector<long>::iterator it;
  it = count.begin();
  while(*it == 0){
    it++;
  }
  max = *it;
  min = *it;
  it++;
  while (it != count.end()){
    long nr = *it;
    it++;
    if (nr == 0) continue;
    if (nr > max) max = nr;
    if (nr < min) min = nr;
  }
  cout << "res " << max - min << endl;
}
void solve2(ifstream& file){
  string line;
  string start;
  file >> start;

  int countLength = ((int)'Z'-'A')+1;
  vector<long> countCh(countLength, 0); // A is 0, Z = 'Z'-'A'

  for (int i = 0; i < start.length(); i++){
    int index = start.at(i) - 'A';
    countCh[index]++;
  }

  map<string, long> polymer;
  for (int i = 1; i < start.length(); i++){
    char ch1 = start.at(i-1);
    char ch2 = start.at(i);
    string str;
    str += ch1;
    str += ch2;
    if (polymer.count(str)){
      polymer[str]++;
    }else{
      polymer[str] = 1;
    }
  }
  //read two empty lines
  getline(file, line);
  getline(file, line);

  // read rules
  map<string, char> rules;
  while(getline(file, line)){
    istringstream linestream(line);
    char ch1;
    char ch2;
    string leftRule;
    linestream >> ch1;
    linestream >> ch2;
    leftRule += ch1;
    leftRule += ch2;
    
    // read -> 
    char ch;
    linestream >> ch;
    linestream >> ch;

    char rightRule;
    linestream >> rightRule;

    rules[leftRule] = rightRule;

//    cout << leftRule << " -> " << rightRule << endl;
  }

  for (int i = 0; i < 40; i++){
    cout << "step " << i+1 << endl;
    map<string, long> newPolymer;
    map<string, long>::iterator it;
    it = polymer.begin();
    while(it != polymer.end()){
      string oldStr = it->first;
      char newChar = (rules.find(oldStr))->second;
      long nrOcc = it->second;

      int index = (int) newChar - 'A';
      countCh[index] += nrOcc;

      string str1, str2;
      str1 += oldStr.at(0);
      str1 += newChar;
      str2 += newChar;
      str2 += oldStr.at(1);
      cout  << str1 << endl;
      cout << str2 << endl;
      if(newPolymer.count(str1)){
        newPolymer[str1] += nrOcc;
      }else{
        newPolymer[str1] = nrOcc;
      }
      if(newPolymer.count(str2)){
        newPolymer[str2] += nrOcc;
      }else{
        newPolymer[str2] = nrOcc;
      }
      it++;
    }

    int nrChars = 0;
    for (int j = 0; j < countCh.size(); j++){
      nrChars += countCh[j];
    }
    cout << "nrChars " <<  nrChars << endl;

    polymer = newPolymer;
//    for (int i = 0; i < polymer.size(); i++){
//      cout << polymer[i] << " ";
//    }
//    cout << endl;
  }
  
  
  
//  map<string, long>::iterator it2;
//  it2 = polymer.begin();
//  while(it2 != polymer.end()){
//    string str = it2->first;
//    long nrOcc = it2->second;
//    char ch1 = str.at(0);
//    char ch2 = str.at(1);
//    count[(int)ch1-'A'] = nrOcc;
//    count[(int)ch2-'A'] = nrOcc;
//
//    it2++;
//  }
  long max = 0;
  long min = 0;

  vector<long>::iterator it;
  it = countCh.begin();
  while(*it == 0){
    it++;
  }
  max = *it;
  min = *it;
  it++;
  while (it != countCh.end()){
    long nr = *it;
    it++;
    if (nr == 0) continue;
    if (nr > max) max = nr;
    if (nr < min) min = nr;
  }
  cout << "res " << max - min << endl;

}
