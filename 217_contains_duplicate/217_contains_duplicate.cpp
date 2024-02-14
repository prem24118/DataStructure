// 217_contains_duplicate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        /*int size = nums.size();
        sort(nums.begin(), nums.end());
        bool flag = false;
        for (int i = 0; i < size-1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                flag = true;
            }
        }
        return flag;*/

        unordered_map<int, int> m;
        for (auto x : nums)
        {
            m[x]++;
        }
        for (auto x : m)
        {
            if (x.second == 2)
                return true;
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> dupl{ 1, 3, 4, 1, 9, 900 };
    Solution sol;
    bool j = sol.containsDuplicate(dupl);

    cout << j;
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
