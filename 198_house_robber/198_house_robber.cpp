// 198_house_robber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n < 2)
            return n;
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n-1];
    }
    int rob2(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> memo(n + 1, 0);
        int x = robUtil(nums, n - 1, memo);
        return x;
    }
    int robUtil(vector<int>& nums, int n, vector<int>& memo)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];
        if (memo[n] != 0)
            return memo[n];
        memo[n] = max(robUtil(nums, n - 1, memo), robUtil(nums, n - 2, memo) + nums[n]);
        return memo[n];
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vec{ 4, 6, 1, 9, 8, 3, 8 };
    Solution sol;
    int out = sol.rob(vec);
    cout << out;
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
