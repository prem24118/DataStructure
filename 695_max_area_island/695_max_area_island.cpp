// 695_max_area_island.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int island = 0;
        int count = 0;
        vector<int> area;
        int maxArea;


        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    DFS(grid, i, j, count);
                    island++;
                    area.push_back(count);
                    count = 0;
                }
            }
        }
        maxArea = *max_element(area.begin(), area.end());
        cout << "largest island" << count << endl;
        return maxArea;
    }

    void DFS(vector<vector<int>>& grid, int row, int col, int& count)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        {
            return;
        }
        if (grid[row][col] == 0)
        {
            return;
        }
        count++;
        grid[row][col] = 0;
        DFS(grid, row, col + 1, count);
        DFS(grid, row, col - 1, count);
        DFS(grid, row + 1, col, count);
        DFS(grid, row - 1, col, count);

    }
};


int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> matr{ {1, 1, 0, 0},
                              {1, 0, 1, 1},
                              {0, 0, 1, 1} };
    /*for (int i = 0; i < matr.size(); i++)
    {
        for (int j = 0; j < matr[0].size(); j++)
        {
            cout << matr[i][j];
        }
    }*/

    Solution output;
    int out = output.numIslands(matr);
    cout << out << "\n";
    /*for (int i = 0; i < matr.size(); i++)
    {
        for (int j = 0; j < matr[0].size(); j++)
        {
            cout << matr[i][j];
        }
    }*/
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
