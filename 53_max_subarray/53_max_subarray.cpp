// 53_max_subarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    //related to leetcode 300, 45,
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int largest_sum = INT16_MIN;
        int j = 0;
        if (n > 0)
        {
            for (j = 0; j < n; j++)
            {
                total = 0;
                for (int i = j; i < n; i++)
                {
                    total += nums[i];
                    if (total > largest_sum)
                    {
                        largest_sum = total;
                    }
                }
            }
        }
        return largest_sum;
    }

    int maxSubArray2(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 0; i < n; i++)
        {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }
        int max = *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vec{ -2, 1, -3, 4, -1, 2,1, -5, 4 };
    Solution sol;
    int maxVal = sol.maxSubArray(vec);
    cout << "max val" << maxVal;

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
