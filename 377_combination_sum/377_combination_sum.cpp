// 377_combination_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int retVal = comboUtil(nums, n - 1, target, dp);
        return retVal;
    }
    int comboUtil(vector<int>& nums, int index, int target, vector<vector<int>>& dp)
    {
        //base case
        if (index == 0)
        {
            if (target % nums[index] == 0)
            {
                return 1;// target / nums[index];
            }
            return 0;
        }
         if(target == 0)
         {
             return 1;
         }
        if (index < 0 || target < 0)
        {
            return 0;
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        //take or not take
        
        int notTake = 0;
        notTake = comboUtil(nums, index - 1, target, dp);
        int take = 0;
        if (nums[index] <= target)
        {
            take = comboUtil(nums, index, target - nums[index], dp);
            int a;
        }
        return dp[index][target] = take + notTake;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> arr = {3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = { 1,2,3 };
    Solution sol;
    int out = sol.combinationSum4(arr2, 4);
    cout << out;
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
