// 300_longest_increasing_subsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //related to leetcode 53, 45,

    int lengthOfLIS(vector<int>& nums) {
        int total_val = 0;
        int maxi = 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] <= dp[j])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    int lengthOfLIS2(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int ans = util(nums, 0, -1, dp);
        return ans;
    }
    int util(vector<int>& nums, int index, int prev, vector<vector<int>>& dp)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        if (dp[index][prev+1] != -1)
        {
            return dp[index][prev + 1];
        }
        int notTake = 0 + util(nums, index + 1, prev, dp);
        int take = 0;
        if(nums[index] > prev)
        {
            take = 1 + util(nums, index + 1, nums[index], dp);
        }
        return dp[index][prev+1] = max(take, notTake);
    }

    /*int lengthOfLIS3(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for (int ind = 1; ind < n; ind++)
        {
            for (int prev_ind = ind - 1; prev_ind < n - 1; prev_ind++)
            {

            }
        }
    }*/
};
int main()
{
    std::cout << "Hello World!\n";
    vector<int> numbers{ 10, 9, 2, 5, 3, 7, 101, 18 };
    Solution sol;
    int x = sol.lengthOfLIS2(numbers);
    cout << x;
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
