// 283_move_0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countzeros = 0;
        int count = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
            {
                countzeros++;
                continue;
            }
            nums[count++] = nums[i];
        }
        for (int i = (size-countzeros); i < size; i++)
            nums[i] = 0;

    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> data{ 3,5,0,3,0 };
    Solution sol;
    sol.moveZeroes(data);
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
