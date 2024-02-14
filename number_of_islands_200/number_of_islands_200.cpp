// number_of_islands_200.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<int>>& grid)
    {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int num_islands = 0;

        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                if (grid[r][c] == 1)
                {
                    DFS(grid, r, c);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }

    void DFS(vector<vector<int>>& grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        {
            return;
        }

        if (grid[row][col] == 0)
        {
            return;
        }
        grid[row][col] = 0;
        DFS(grid, row + 1, col);
        DFS(grid, row - 1, col);
        DFS(grid, row, col + 1);
        DFS(grid, row, col - 1);


    }
};

class Solution2
{
public:
    int numIslands(vector<vector<int>>& grid)
    {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int num_islands = 0;
        vector<vector<int>> dp(num_rows, vector<int>(num_cols, -1));
        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                if (grid[r][c] == 1)
                {
                    DFS(grid, r, c, dp);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }

    int DFS(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        {
            return 0;
        }

        if (grid[row][col] == 0)
        {
            return 0;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        grid[row][col] = 0;
        dp[row][col] = DFS(grid, row + 1, col, dp);
        + DFS(grid, row - 1, col, dp);
        + DFS(grid, row, col + 1, dp);
        + DFS(grid, row, col - 1, dp);
        return dp[row][col];

    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> matr{ {1, 1, 0, 0},
                              {1, 0, 0, 0},
                              {0, 0, 0, 1} };
    /*for (int i = 0; i < matr.size(); i++)
    {
        for (int j = 0; j < matr[0].size(); j++)
        {
            cout << matr[i][j];
        }
    }*/
    
    Solution2 output;
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
