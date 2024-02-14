// 64_minimum_path_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>> matrix(rows, vector<int>(columns, 0));
        matrix[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++)
        {
            matrix[i][0] = grid[i][0] + matrix[i - 1][0];
        }
        for (int j = 1; j < columns; j++)
        {
            matrix[0][j] = grid[0][j] + matrix[0][j - 1];
        }
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < columns; j++)
            {
                matrix[i][j] = min((grid[i][j] + matrix[i - 1][j]), (grid[i][j] + matrix[i][j - 1]));
            }
        }
        return matrix[rows - 1][columns - 1];

    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> vec{
        {3, 5, 9, 2, 1, 1},
        {7, 6, 4, 4, 1, 5},
        {8, 2, 1, 5, 4, 1},
        {5, 4, 0, 2, 2, 8}
    };
    Solution sol;
    int out = sol.minPathSum(vec);
    cout << out;
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
