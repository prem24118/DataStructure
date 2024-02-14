// 31_next_permutation_design.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        if (n > 2)
        {
            int i, j;
            for (i = n - 2; i >= 0; i--)
            {
                if (nums[i] < nums[i + 1])
                    break;
            }
            if (i < 0)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
            else
            {
                for (j = n - 1; j > i; j--)
                {
                    if (nums[i] < nums[j])
                        break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
int main()
{
    std::cout << "Hello World!\n";
    vector<int> vec = { 1,3,2 };
    Solution sol;
    sol.nextPermutation(vec);
    cout << endl;
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
