// 733_flood_fll_graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        vector<vector<int>> copy = image;
        int nrows[] = { -1, 0, 1, 0 };
        int ncols[] = { 0, 1, 0, -1 };
        dfs(sr, sc, copy, image, nrows, ncols, oldColor, newColor);
    }
private:
    void dfs(int row, int col, vector<vector<int>>& copy, vector<vector<int>>& image, int nrows[], int ncols[], int oldColor, int newColor)
    {
        //copy[row][col] = newColor;
        int m = image.size();
        int n = image[0].size();
        /*for (int i = 0; i < 4; i++)
        {
            int r = row + nrows[i];
            int c = col + ncols[i];
            if (r >= 0 && r < m && c >= 0 && c < n &&
                image[r][c] == oldColor && copy[r][c] != newColor)
            {
                dfs(r, c, copy, image, nrows, ncols, oldColor, newColor);
            }
        }*/
        if (row < 0 && row >= m && col < 0 && col >= n &&
            image[row][col] == oldColor && copy[row][col] != newColor)
        {
            return;
        }
        copy[row][col] = newColor;
        dfs(row + 1, col, copy, image, nrows, ncols, oldColor, newColor);
        dfs(row - 1, col, copy, image, nrows, ncols, oldColor, newColor);
        dfs(row, col + 1, copy, image, nrows, ncols, oldColor, newColor);
        dfs(row, col - 1, copy, image, nrows, ncols, oldColor, newColor);

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
