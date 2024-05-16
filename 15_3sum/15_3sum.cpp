// 15_3sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int count_three_sums = 0;
        int total = 0;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == nums[i + 1])
                continue;
            int j = i+1;
            int k = nums.size() - 1;
            while (j<k)
            {
                int total_sum = nums[i] + nums[j] + nums[k];
                if (total_sum == total)
                {
                    answer.push_back({ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                }
                else if (total_sum < total)
                    j++;
                else
                    k--;
            }
        }
        return answer;
    }
    vector<vector<int>> sum3(vector<int>&nums, int target)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int total_sum = nums[i] + nums[j] + nums[k];
                if (total_sum == target)
                {
                    ans.push_back({ i, j, k });
                    j++;
                    k--;
                }
                else if (total_sum < target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};

int main()
{
    std::cout << "Hello World!\n";
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
