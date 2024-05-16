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
    int util(vector<int>& nums, int index, int prev_ind, vector<vector<int>>& dp)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        if (dp[index][prev_ind +1] != -1)
        {
            return dp[index][prev_ind + 1];
        }
        int notTake = 0 + util(nums, index + 1, prev_ind, dp);
        int take = 0;
        if(prev_ind == -1 || nums[index] > nums[prev_ind])
        {
            take = 1 + util(nums, index + 1, index, dp);
        }
        return dp[index][prev_ind +1] = max(take, notTake);
    }
/* This method goes from the back, tries to make a dp array where that specific index from the back has longest subsequence
from its position till the end. first for loop goes back, 2nd for loop goes from which element we are at to the end
{10, 9, 2, 5, 3, 4} so dp[5] = 1, dp[4] = 1 + 1, dp[3] = 1, dp[2] = 1 + 2, dp [1] = 1, dp[0] = 1
this statement makes sure you go through all elements in 2nd loop and choose the max dp value if current is smaller than jth position*/
    int lengthOfLIS3(vector<int>& nums) {
        int total_val = 0;
        int maxi = 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = n-1; i > 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (nums[i - 1] < nums[j])
                {
                    dp[i - 1] = max(dp[i - 1], dp[j] + 1);

                }
                else
                    continue;
            }
        }
        return *max_element(dp.begin(), dp.end());
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
    vector<int> numbers2{2, 15, 3, 7, 8, 6, 18};
//    vector<int> numbers2{0, 1, 0, 3, 2, 3};
//    vector<int> numbers2{10, 9, 2, 5, 3, 4};
    Solution sol;
    int x = sol.lengthOfLIS3(numbers2);
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
