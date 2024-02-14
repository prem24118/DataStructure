// 289_matrix_game_of_life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int count = 0, rows = board.size(), columns = board[0].size();
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                count = util(r, c, rows, columns, board);
                if (board[r][c] == 0)
                {
                    if (count == 3)
                        board[r][c] = 2;
                }
                if (board[r][c] == 1)
                {
                    if (count < 2 || count > 3)
                        board[r][c] = 3;
                }
            }
        }
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                if (board[r][c] == 2)
                    board[r][c] = 1;
                if (board[r][c] == 3)
                    board[r][c] = 0;
            }
        }
    }
    int util(int i, int j, int maxRow, int maxCol, vector<vector<int>>& grid)
    {
        int numberAlive = 0;
        if (i > 0)
            if (grid[i - 1][j] == 1 || grid[i - 1][j] == 3)
                numberAlive++;
        if (i < maxRow - 1)
            if (grid[i + 1][j] == 1 || grid[i + 1][j] == 3)
                numberAlive++;
        if (j > 0)
            if (grid[i][j - 1] == 1 || grid[i][j - 1] == 3)
                numberAlive++;
        if (j < maxCol - 1)
            if (grid[i][j + 1] == 1 || grid[i][j + 1] == 3)
                numberAlive++;
        if (i > 0 && j > 0)
            if (grid[i - 1][j - 1] == 1 || grid[i - 1][j - 1] == 3)
                numberAlive++;
        if (i < maxRow - 1 && j < maxCol - 1)
            if (grid[i + 1][j + 1] == 1 || grid[i + 1][j + 1] == 3)
                numberAlive++;
        if (i < maxRow - 1 && j > 0)
            if (grid[i + 1][j - 1] == 1 || grid[i + 1][j - 1] == 3)
                numberAlive++;
        if (i > 0 && j < maxCol - 1)
            if (grid[i - 1][j + 1] == 1 || grid[i - 1][j + 1] == 3)
                numberAlive++;
        return numberAlive;
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
