// 54_spiral_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        char dir = 'r';
        int left = 0;
        int right = matrix[0].size();
        int top = 0; 
        int bottom = matrix.size();
        vector<int> result(right * bottom, 0);
        while (left <= right and top <= bottom)
        {
            if (dir == 'r')
            {
                for (int i = left; i <= right; i++)
                {
                    result.push_back(matrix[top][i]);
                }
                top++;
                dir = 'd';
            }
            if (dir == 'd')
            {
                for (int i = top; i <= bottom; i++)
                {
                    result.push_back(matrix[i][right]);
                }
                right--;
                dir = 'l';
            }
            if (dir == 'l')
            {
                for (int i = right; i >= left; i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir = top;
            }
        }
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
