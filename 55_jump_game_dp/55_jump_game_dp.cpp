// 55_jump_game_dp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        bool ans = util(nums, 0);
        return ans;
    }
    bool util(vector<int>& nums, int index)
    {
        int n = nums.size();
        if (index == n - 1)
            return true;
        else if (index >= n || nums[index] == 0)
            return false;
        for (int i = 0; i < nums[index]; i++)
        {
            if(util(nums, index + 1))
                return true;
        }
    }

    bool recursive(vector<int>& nums, int index)
    {
        int n = nums.size();
        if (index >= n - 1)
            return true;
        if (nums[index] == 0)
            return false;
        for (int i = index + 1; i <= index + nums[index]; i++)
        {
            //the index you are at (i) needs to be less that total indices, but the value in that index (arr[i]) needs to be greater than the size of arr (n) which
            //means we will be past the last index (n-1) of the nums array
            if (i <= n - 1 && recursive(nums, i))
                return true;
        }
        return false;
    }
    //this solution is similar to the stock problem in Leetcode 122 and 121
    bool canJump2(vector<int>& nums)
    {
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mx = max(mx, i + nums[i]);
            if (mx >= nums.size() - 1)
                return true;
            //if we reach an index, say i, and that is actually the max value we couldve reached from prior jumps and that has a value 0 as in nums[i] == 0, then we cant go further
            if (mx == i && nums[i] == 0)
                return false;
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution sol;
    vector<int> nums = { 3, 2, 1, 0, 4 };
    bool ans = sol.canJump(nums);
    cout << ans;
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
