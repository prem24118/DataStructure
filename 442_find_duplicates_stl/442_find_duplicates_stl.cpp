// 442_find_duplicates_stl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        unordered_map<int, int> duplicates;
        vector<int> result;
        for (auto& num : nums)
        {
            duplicates[num]++;
        }
        for (auto& dup : duplicates)
        {
            if (dup.second > 1)
                result.push_back(dup.first);
        }
        return result;
    }
    vector<int> findDuplicates2(vector<int>& nums)
    {
        vector<int> result;
        set<int> duplicates;// (nums.begin(), nums.end());
        for (const auto& num : nums)
        {
            if (duplicates.find(num) != duplicates.end())
            {
                result.push_back(num);
            }
            else
            {
                duplicates.insert(num);
            }
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums {4, 3, 2, 7, 8, 2, 3, 1};
    Solution sol;
    vector<int> ans = sol.findDuplicates(nums);
    cout << "ans";
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
