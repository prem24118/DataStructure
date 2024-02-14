// 45_jump_game2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int jumpGame(vector<int>& nums)
    {
        int mx = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, i + nums[i]);
        }
        vector<int> dp(n + mx, 1e9);
        dp[0] = 0;
        for(int index = 0; index < n; index++)
        {
            for (int i = index + 1; i <= index + nums[index]; i++)
            {
                dp[i] = min(dp[i], 1 + dp[index]);
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums = { 2, 3, 1, 1, 4 };
    Solution sol;
    int min_jumps = sol.jumpGame(nums);
    cout << min_jumps;
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
