// 55_jump_game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (auto x : nums)
        {
            int i = x;
            while (i <= n - 1)
            {
                if (i > n - 1)
                    return false;
                if (i == n - 1)
                    return true;
                i = nums[i];
                if (i == 0 && i != n - 1)
                    return false;
            }
        }
        return false;
    }
    bool canJump2(vector<int>& nums)
    {
        int n = size(nums);
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, i + nums[i]);
            if (mx >= n - 1)
                return true;
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
    vector<int> vec{ 3,2,1,0,4 };
    bool ans = sol.canJump(vec);
    cout << "the ans";
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
