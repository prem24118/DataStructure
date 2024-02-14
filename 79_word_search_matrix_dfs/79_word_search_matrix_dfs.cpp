// 79_word_search_matrix_dfs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (util(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
    bool util(vector<vector<char>>& board, int r, int c, string word)
    {
        if (word.size() == 0)
            return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[0])
        {
            return false;
        }
        string str = word.substr(1);
        char ch;
        ch = board[r][c];
        board[r][c] = '*';
        bool ret = util(board, r - 1, c, str) || util(board, r + 1, c, str) || util(board, r, c - 1, str) || util(board, r, c + 1, str);
        board[r][c] = ch;
        return ret;
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
