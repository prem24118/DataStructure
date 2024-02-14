// 46_permutation_recursion_dfs_dp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// ///////////////////////////
/// Check out this
/// https://www.youtube.com/watch?v=YK78FU5Ffjw&ab_channel=takeUforward
/// </summary>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> visited(nums.size(), false);
        util(nums, ds, ans, visited);
        return ans;
    }

    void util(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& visited) 
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                ds.push_back(nums[i]);
                util(nums, ds, ans, visited);
                ds.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution sol;
    vector<int> nums = { 4, 3, 8 };
    vector<vector<int>> ans;
    ans = sol.permute(nums);
    for (auto dp : ans)
    {
        for (auto element : dp)
        {
            cout << element << " ";
        }
        cout << "\n";
    }
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
