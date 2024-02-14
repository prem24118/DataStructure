// 986_interval_intersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> a;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size())
        {
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);
            if (l < r)
            {
                a.push_back({ l, r });
            }
            if (firstList[i][1] > secondList[j][1])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return a;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> a{ {5, 10},
                          {12, 15} };
    vector<vector<int>> b{ {1, 7},
                      {14, 20} };
    vector<vector<int>> c;

    Solution out;
    c = out.intervalIntersection(a, b);
    return 1;
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
