// 311_sparse_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include < vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2)
    {
        int row = mat1.size();
        int column = mat2[0].size();
        int middle = mat1[0].size();
        vector<vector<int>> result(row, vector<int>(column, 0));
        if (mat1[0].size() == mat2.size())
        {
            for (int r = 0; r < row; r++)
            {
                for (int element = 0; element <= middle; element++)
                {
                    if (mat1[r][element] != 0)
                    {
                        for (int c = 0; c < column; c++)
                        {
                            result[r][c] += mat1[r][element] * mat2[element][c];
                        }
                    }
                }
            }
        }
        return result;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> v1 { {1, 2, 1},
        { 3, 4, 3 },
        { 5 , 6, 5 }};
    vector<vector<int>> v2 {{3}, { 2 }, { 1 }};
    Solution sol;
    vector<vector<int>> v3;
    v3 = sol.multiply(v1, v2);
    return 0;
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
