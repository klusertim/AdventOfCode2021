#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void readInFile();
void solve1(ifstream &file1);
void solve2(ifstream &file2);
void printVec(vector<vector<int>> &vec);
int countBasin(int i, int j, vector<vector<int>>& field, vector<vector<bool>>& marked);

void printVec(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    std::ifstream file1("input.txt");
    std::ifstream file2("input.txt");
    //  readInFile();
    if (file1.is_open() && file2.is_open())
    {
        //problem1(file);
//        solve1(file1);
        solve2(file2);
    }
    else
    {
        cout << "unable to open file";
    }
    file1.close();
    file2.close();
    return 0;
}

void readInFile()
{
    // freopen("input.txt", "r", stdin); // reads the textfile to the input
    freopen("output.txt", "w", stdout); // writes the output to the output file
    freopen("error.txt", "w", stderr);  // error
}

void solve1(ifstream &file)
{
    vector<vector<int>> points;
    string line;
    while (getline(file, line))
    {
        vector<int> pointLine;
        cout << line << endl;
        for (char ch : line)
        {
            int p = ch - '0';
            //      cout << ch << " ";
            pointLine.push_back(p);
            cout << pointLine.back() << " ";
        }
        cout << endl;
        points.push_back(pointLine);
        cout << "size " << points.back().size() << endl;
    }
    printVec(points);

    vector<int> resVec;
    for (int i = 0; i < points.size(); i++)
    {
        cout << "size j " << points[i].size() << endl;
        int size2 = points[i].size();
        for (int j = 0; j < size2; j++)
        {
            cout << " j " << j << endl;
            int el = points[i][j];
            if (((i - 1) >= 0) && (el >= points[(i - 1)][j]))
            {
                cout << "1" << el << endl;
                continue;
            }
            if (((i + 1) <= (points.size() - 1)) && (el >= points[(i + 1)][j]))
            {

                cout << "2" << el << endl;
                continue;
            }
            if (((j - 1) >= 0) && (el >= points[i][(j - 1)]))
            {

                cout << "3 " << el << endl;
                continue;
            }
            if (((j + 1) <= (points[i].size() - 1)) && (el >= points[i][(j + 1)]))
            {

                cout << "4 " << el << endl;
                continue;
            }
            cout << "el " << el << endl;
            resVec.push_back(el);
        }
    }
    int res = 0;
    for (int i = 0; i < resVec.size(); i++)
    {
        res += (resVec[i] + 1);
    }
    cout << "res " << res << endl;
}
void solve2(ifstream &file)
{
    vector<vector<int>> points;
    string line;
    while (getline(file, line))
    {
        vector<int> pointLine;
        for (char ch : line)
        {
            int p = ch - '0';
            //      cout << ch << " ";
            pointLine.push_back(p);
        }
        points.push_back(pointLine);
    }
    printVec(points);

    vector<int> resVec;
    vector<int> maxBasin(3);
    maxBasin = {0};
    vector<vector<bool>> marked(points.size(), vector<bool>(points[0].size(), false)); // have to initialize this way
//    for (int i = 0; i < points.size() ; i++){
//        cout << marked[i][2] << endl;
//    }


    for (int i = 0; i < points.size(); i++)
    {
        int size2 = points[i].size();
        for (int j = 0; j < size2; j++)
        {
            int el = points[i][j];
            if ((i - 1) >= 0 && el >= points[(i - 1)][j])
            {
                continue;
            }
            if (((i + 1) <= (points.size() - 1)) && (el >= points[(i + 1)][j]))
            {
                continue;
            }
            if (((j - 1) >= 0) && (el >= points[i][(j - 1)]))
            {
                continue;
            }
            if (((j + 1) <= (points[i].size() - 1)) && (el >= points[i][(j + 1)]))
            {
                continue;
            }
//            resVec.push_back(el);
            cout << el << endl;
            // we have a low point
            int sizeB = countBasin(i, j, points, marked);
            if (sizeB > maxBasin[0]){
                maxBasin[0] = sizeB;
                sort(maxBasin.begin(), maxBasin.begin() + 3); // doesn't work with maxBasin.end()
            }
            cout << i << ", " << j << " lowpoint " << el << " size " << sizeB << endl;
        }
    }
    cout << "basin" << endl;
    for (int i = 0; i < 3; i++){
        cout << maxBasin[i] << endl;
    }
    long res = (maxBasin[0] * maxBasin[1] * maxBasin[2]);
    cout << "res " << res << endl;
}
int countBasin(int i, int j, vector<vector<int>>& field, vector<vector<bool>>& marked){
    // mark the counted points with 10
    // only call the function if its a point bigger than the caller

    int thisNr = field[i][j];
    //cout << " washere " << endl;
    // check if not 9 or 10
    if (thisNr >= 9 || marked[i][j]) return 0;
    marked[i][j] = true; // set point as visited

    int nrPoints = 1;
    
    int m = field.size();
    int n = field[0].size();
    // don't check diagonal points
    if (i+1 < m && field[i+1][j] > thisNr) nrPoints += countBasin(i+1, j, field, marked);
    if (i-1 >= 0 && field[i-1][j] > thisNr) nrPoints += countBasin(i-1, j, field, marked);
    if (j+1 < n && field[i][j+1] > thisNr) nrPoints += countBasin(i, j+1, field, marked);
    if (j-1 >= 0 && field[i][j-1] > thisNr) nrPoints += countBasin(i, j-1, field, marked);
//    cout << " washere " << endl;

    return nrPoints;
        

}
