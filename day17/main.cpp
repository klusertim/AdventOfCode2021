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
typedef long long ll;

void readInFile();
void solve1(ifstream &file1);
void solve2(ifstream &file2);
int shoot(int x, int y, int ymin, int ymax, int xmin, int xmax);
int shoot2(int x, int y, int ymin, int ymax, int xmin, int xmax);

int main()
{
    std::ifstream file1("input.txt");
    std::ifstream file2("input.txt");
    //  readInFile();
    if (file1.is_open() && file2.is_open())
    {
        //problem1(file);
        solve1(file1);
        //solve2(file2);
    }
    else
    {
        std::cout << "unable to open file";
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
    // read input
    string str;
    // read target area:
    file >> str;
    file >> str;

    char ch;
    // read x=
    file >> ch;
    file >> ch;

    int xmin, xmax, ymin, ymax;
    file >> xmin;

    // read ..
    file >> ch;
    file >> ch;

    file >> xmax;

    // read ,y=
    file >> ch;
    file >> ch;
    file >> ch;

    file >> ymin;

    file >> ch;
    file >> ch;

    file >> ymax;
    std::cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;

    // solve

    // x from 0 to xmax
    // form y negative to 500 (eigentlich xmax + 1, da in jeder iteration y nur um 1 abnimmt)

    // int maximal = ymin;
    // for (int x = 0; x < xmax; x++)
    // {
    //     for (int y = ymin; y < 1000; y++)

    //     {
    //         int thisMax = shoot(x, y, ymin, ymax, xmin, xmax);
    //         if (thisMax > maximal)
    //         {
    //             maximal = thisMax;
    //         }
    //     }
    // }
    // std::cout << maximal << endl;

    // better solving technique
    /*
        Because the initial speed y reduces by one in each step by 1 
        until it is 0 and then again increases by 1 in each step, 
        we will reach the coordinate y = 0 with yspeed as the negation of the number.
        we'll reach the highest y coordinate if the end-speed is maximal. This is if the last step has size ymin
        The initial y speed is the end-speed-1. 
    */

    cout << "res1 " << (ymin * (ymin + 1)) / 2 << endl;
}

int shoot(int x, int y, int ymin, int ymax, int xmin, int xmax)
{
    int max = ymin;
    int posx = 0;
    int posy = 0;
    while (posx <= xmax && posy >= ymin)
    {
        // cout << "y " << y << endl;
        // cout << "x " << x << endl;
        if (posx <= xmax && posx >= xmin && posy <= ymax && posy >= ymin)
        {
            //cout << "success " << endl;
            // cout << max << endl;

            return max;
        }
        if (x > 0)
        {
            x -= 1;
        }
        else if (x < 0)
        {
            x += 1;
        }

        y -= 1;

        posx += x;
        posy += y;

        // update max y
        if (max < posy)
        {
            max = posy;
        }
    }
    //cout << "break" << endl;
    return ymin;
}

void solve2(ifstream &file)
{
    // read input
    string str;
    // read target area:
    file >> str;
    file >> str;

    char ch;
    // read x=
    file >> ch;
    file >> ch;

    int xmin, xmax, ymin, ymax;
    file >> xmin;

    // read ..
    file >> ch;
    file >> ch;

    file >> xmax;

    // read ,y=
    file >> ch;
    file >> ch;
    file >> ch;

    file >> ymin;

    file >> ch;
    file >> ch;

    file >> ymax;
    std::cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;

    int res2 = 0;
    for (int x = 0; x <= xmax + 1; x++)
    {
        for (int y = ymin; y < 1000; y++)

        {
            res2 += shoot2(x, y, ymin, ymax, xmin, xmax);
        }
    }
    std::cout << "res2 " << res2 << endl;
}
int shoot2(int x, int y, int ymin, int ymax, int xmin, int xmax)
{
    int max = ymin;
    int posx = 0;
    int posy = 0;
    while (posx <= xmax && posy >= ymin)
    {
        // cout << "y " << y << endl;
        // cout << "x " << x << endl;
        if (posx <= xmax && posx >= xmin && posy <= ymax && posy >= ymin)
        {
            //cout << "success " << endl;
            // cout << max << endl;

            return 1;
        }
        if (x > 0)
        {
            x -= 1;
        }
        else if (x < 0)
        {
            x += 1;
        }

        y -= 1;

        posx += x;
        posy += y;

        // update max y
        if (max < posy)
        {
            max = posy;
        }
    }
    //cout << "break" << endl;
    return 0;
}
