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
void addEdge(vector<vector<int>>& adList, int i, int j);
int countPaths(const vector<vector<int>>& adList, const vector<int>& bigCave, vector<int> visited, int start, int end, vector<int> reklist);
int countPaths2(const vector<vector<int>>& adList, const vector<int>& bigCave, vector<int> visited, int start, int thisNode, int end, vector<int> reklist, bool visSecond);

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
  vector<vector<int>> adList;
  map<string, int> caveMap;
  vector<int> bigCave;

  // read input
  string line;
  int nodeCount = 0;
  while(getline(file, line)){
    istringstream lineStream(line);
    string s1;
    string s2;
    getline(lineStream, s1, '-');
    getline(lineStream, s2);
//    cout <<  s1 << " - " << s2 << endl;
    auto refU = caveMap.find(s1);
    auto refV = caveMap.find(s2);
    int u;
    int v;
    
    for (char ch : s1){
      if (ch == ' ') cout << "space";
    }
    for (char ch : s2){
      if (ch == ' ') cout << "space";
    }

    if (!caveMap.count(s1)){ // is 1 if the map contains the element
      caveMap[s1] = nodeCount;
      u = nodeCount;
      nodeCount++;
      vector<int> vec;
      adList.push_back(vec);
      // check if big cave
      if ((int)(s1.at(0)) < 97){
        bigCave.push_back(1); //big cave
      }else{
        bigCave.push_back(0);
      }
    }else{
      u = (refU->second);
    }
    if (!caveMap.count(s2)){
      caveMap[s2] = nodeCount;
      v = nodeCount;
      nodeCount++;
      vector<int> vec;
      adList.push_back(vec);

      if ((int)(s2.at(0)) < 97){
        bigCave.push_back(1); //big cave
      }else{
        bigCave.push_back(0);
      }
    }else{
      v = (refV->second);
    }

    addEdge(adList, u, v);

    cout <<  s1 << ": " << u << " - " << s2 << ": " << v << endl;


  }
    for (int i = 0; i < adList.size(); i++){
      for (int j = 0; j < adList[i].size(); j++){
        cout << i << "-" << adList[i][j] << endl;
      }
    }

    // count paths
    vector<int> visited(adList.size(), 0); // pass as copy to see the visited edges 

    int start = caveMap["start"];
    int end = caveMap["end"];
//    visited[start] = 1;
    vector<int> reklist;
//    reklist.push_back(start);
    cout << " size " << adList[start].size() << endl;
    cout << "bool " << visited[2] << endl; 

    cout << countPaths(adList, bigCave, visited, start, end, reklist);
}
void solve2(ifstream& file){
  vector<vector<int>> adList;
  map<string, int> caveMap;
  vector<int> bigCave;

  // read input
  string line;
  int nodeCount = 0;
  while(getline(file, line)){
    istringstream lineStream(line);
    string s1;
    string s2;
    getline(lineStream, s1, '-');
    getline(lineStream, s2);
//    cout <<  s1 << " - " << s2 << endl;
    auto refU = caveMap.find(s1);
    auto refV = caveMap.find(s2);
    int u;
    int v;
    
    for (char ch : s1){
      if (ch == ' ') cout << "space";
    }
    for (char ch : s2){
      if (ch == ' ') cout << "space";
    }

    if (!caveMap.count(s1)){ // is 1 if the map contains the element
      caveMap[s1] = nodeCount;
      u = nodeCount;
      nodeCount++;
      vector<int> vec;
      adList.push_back(vec);
      // check if big cave
      if ((int)(s1.at(0)) < 97){
        bigCave.push_back(1); //big cave
      }else{
        bigCave.push_back(0);
      }
    }else{
      u = (refU->second);
    }
    if (!caveMap.count(s2)){
      caveMap[s2] = nodeCount;
      v = nodeCount;
      nodeCount++;
      vector<int> vec;
      adList.push_back(vec);

      if ((int)(s2.at(0)) < 97){
        bigCave.push_back(1); //big cave
      }else{
        bigCave.push_back(0);
      }
    }else{
      v = (refV->second);
    }

    addEdge(adList, u, v);

    cout <<  s1 << ": " << u << " - " << s2 << ": " << v << endl;


  }
    for (int i = 0; i < adList.size(); i++){
      for (int j = 0; j < adList[i].size(); j++){
        cout << i << "-" << adList[i][j] << endl;
      }
    }

    // count paths
    vector<int> visited(adList.size(), 0); // pass as copy to see the visited edges 

    int start = caveMap["start"];
    int end = caveMap["end"];
//    visited[start] = 1;
    vector<int> reklist;
//    reklist.push_back(start);
    cout << " size " << adList[start].size() << endl;
    cout << "bool " << visited[2] << endl; 

    cout << countPaths2(adList, bigCave, visited, start, start, end, reklist, false);
}

int countPaths(const vector<vector<int>>& adList, const vector<int>& bigCave, vector<int> visited, int start, int end, vector<int> reklist){
  reklist.push_back(start);
  if (!bigCave[start]){
    visited[start] = 1;
  }
  // base case
  if (start == end){
//    cout << " end" << endl;
    for (int i = 0; i < reklist.size(); i++){
      cout << reklist[i] << " ";
    }
    cout << endl;
    return 1;
  }
  // print list
//  cout << "adlist of " << start << " ";
//  for (int i = 0; i < adList[start].size(); i++){
//    cout << adList[start][i] << " ";
//  }
//  cout << endl;
  int res = 0;
  for (int i = 0; i < adList[start].size(); i++){
    int node = adList[start][i];
    for (int j = 0; j < reklist.size(); j++){
      cout << reklist[j] << " ";
    }
    cout << endl;
    if (!visited[node]){
//    cout << "bool " << visited[2] << endl; 
//      reklist.push_back(node);
      res += countPaths(adList, bigCave, visited, node, end, reklist);
    }else{
      cout << "already visited " << node << endl;
    }

  }
  
  return res;
}

int countPaths2(const vector<vector<int>>& adList, const vector<int>& bigCave, vector<int> visited, int start, int thisNode, int end, vector<int> reklist, bool visSecond){
  reklist.push_back(start);
  if (!bigCave[thisNode]){
    visited[thisNode] = 1;
  }
  // base case
  if (thisNode == end){
//    cout << " end" << endl;
    for (int i = 0; i < reklist.size(); i++){
      cout << reklist[i] << " ";
    }
    cout << endl;
    return 1;
  }
  // print list
//  cout << "adlist of " << start << " ";
//  for (int i = 0; i < adList[start].size(); i++){
//    cout << adList[start][i] << " ";
//  }
//  cout << endl;
  int res = 0;
  for (int i = 0; i < adList[thisNode].size(); i++){
    int node = adList[thisNode][i];
    for (int j = 0; j < reklist.size(); j++){
      cout << reklist[j] << " ";
    }
    cout << endl;
    if (!visited[node] and !visSecond){
//    cout << "bool " << visited[2] << endl; 
//      reklist.push_back(node);
      res += countPaths2(adList, bigCave, visited, start, node, end, reklist, false);
    }else{
      if (visited[node]){
        if (!visSecond && node != end && node!=start){
          cout << "was here " << endl;
          res += countPaths2(adList, bigCave, visited, start, node, end, reklist, true);
        }
      }
      if (!visited[node]){ // case of big case
        res += countPaths2(adList, bigCave, visited, start, node, end, reklist, true);
      }

    }

  }
  
  return res;
}

void addEdge(vector<vector<int>>& adList, int i, int j){
  adList[i].push_back(j);
  adList[j].push_back(i);
}
