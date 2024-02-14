// 36_sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> board)
    {
        int R = board.size();
        int C = board[0].size();
        unordered_map<char, int> row[9];
        unordered_map<char, int> col[9];
        unordered_map<char, int> box[9];

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                char ch = board[i][j];
                if (ch != '.' && (row[i][ch]++ > 0 || col[j][ch]++ > 0 || box[(i / 3) * 3 + j / 3][ch]++ > 0))
                    return true;
            }
        }
        return false;
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
