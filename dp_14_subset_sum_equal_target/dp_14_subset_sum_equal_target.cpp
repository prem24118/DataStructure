// dp_14_subset_sum_equal_target.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool subsetSumToK(int n, int target, vector<int>& arr)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return subsetSumUtil(n - 1, target, arr, dp);
    }
    bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return arr[0] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool notTake = subsetSumUtil(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
        {
            take = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take or notTake;
    }

    bool subsetSumToK2(int n, int target, vector<int>& arr)
    {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (arr[0] <= target)
            dp[0][arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 1; tar <= target; tar++)
            {
                bool notTake = dp[ind - 1][tar];
                bool take = false;
                if (arr[ind] <= tar)
                    take = dp[ind - 1][tar - arr[ind]];
                dp[ind][tar] = take or notTake;
            }
        }
        return dp[n - 1][target];
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> arr = { 5, 6, 7, 8, 9 };
    int target = 9;
    int n = arr.size();
    Solution sol;
    if (sol.subsetSumToK2(n, target, arr))
        cout << "subset found";
    else
        cout << "subset NOT found";
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
