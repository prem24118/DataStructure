// 1041_robot_bound_circle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector < vector<int>> d = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        for (char &ins : instructions)
        {
            if (ins == 'R')
            {
                i = (i + 1) % 4;
            }
            else if (ins == 'L')
            {
                i = (i + 3) % 4;
            }
            else
            {
                x += d[i][0];
                y += d[i][1];
            }
        }

        return x == 0 && y == 0 || i > 0;

    }
    bool isRobotBounded2(string instructions)
    {
        //char has ' ' single quotes
        char dir = 'N';
        int x = 0, y = 0;
        for (char ins : instructions)
        {
            if (ins == 'G')
            {
                if (dir == 'N')
                    y += 1;
                else if (dir == 'S')
                    y += -1;
                else if (dir == 'E')
                    x += 1;
                else if (dir == 'W')
                    x += -1;
            }
            if (ins == 'L')
            {
                if (dir == 'N')
                    dir = 'W';
                else if (dir == 'W')
                    dir = 'S';
                else if (dir == 'S')
                    dir = 'E';
                else if (dir == 'E')
                    dir = 'N';
            }
            if (ins == 'R')
            {
                if (dir == 'N')
                    dir = 'E';
                else if (dir == 'E')
                    dir = 'S';
                else if (dir == 'S')
                    dir = 'W';
                else if (dir == 'W')
                    dir = 'N';
            }
        }
        return ((x == 0 && y == 0) || dir != 'N');
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution out;
    bool output = out.isRobotBounded2("GGLLL");
    cout << output;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
