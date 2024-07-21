// 238_product_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prod(size, 1);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i != j)
                    prod[i] *= nums[j];
                else
                    continue;
            }
        }
        return prod;
    }

    vector<int> productExceptSelf2(vector<int>& nums) {
        int size = nums.size();
        vector<int> prod(size, 1);
        vector<int> dp(size + 1, 1);
        dp[0] = 1;
        for (int i = 1; i <= size; i++)
        {
            dp[i] = dp[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            dp[i] *= right;
            right *= nums[i];
        }
        return prod;
    }
};

int main()
{
    vector<int> vec { 2, 3, 4, 5};
    vector<int> ans;
    Solution sol;
    ans = sol.productExceptSelf2(vec);
    cout << "ans";
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
