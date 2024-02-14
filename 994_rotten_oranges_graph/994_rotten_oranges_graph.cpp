// 994_rotten_oranges_graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Solution
{
public:
    int orangeRotting(vector<vector<int>>& grid)
    {
        
        queue < pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector < vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    visited[i][j] = 2;
                    q.push({ { i,j }, 0 });
                }
            }
        }

        int time = -1;
        int deltarow[] = { -1, 0, 1, 0 };
        int deltacol[] = { 0, 1, 0, -1 };
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int neighborrow = r + deltarow[i];
                int neighborcol = c + deltacol[i];
                if (neighborrow >= 0 && neighborrow < n && neighborcol >= 0 && neighborcol < m && visited[neighborrow][neighborcol] != 2 && grid[neighborrow][neighborcol] == 1)
                {
                    q.push({ {neighborrow, neighborcol}, t + 1 });
                    visited[neighborrow][neighborcol] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }
        return time;
    }
};
int main()
{
    std::cout << "Hello World!\n";
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
