// 1_two_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
            {
                vector<int>v{ i, mp[target - nums[i]] };
                return v;
            }
        }
        return vector<int>{ -1, -1};
    }
    vector<int> answer;
    vector<int> twoSum2(vector<int>& nums, int target, int index)
    {
        if (target == 0)
        {
            answer.push_back(index);
            return answer;
        }
        if (target < 0)
        {
            return vector<int> {NULL};
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int remainder = target - nums[i];
            twoSum2(nums, remainder, i);
        }
    }

};

int main()
{

    // Initialize container
    map<int, int> mp;

    // Insert elements in random order
    mp.insert({ 3, 30 });
    mp.insert({ 1, 40 });
    mp.insert({ 2, 20 });
    mp.insert({ 4, 50 });

    cout << "Elements from position of 3 in the map are : \n";
    cout << "KEY\tELEMENT\n";

    // find() function finds the position
    // at which 3 is present
    for (auto itr = mp.find(3); itr != mp.end(); itr++) {

        cout << itr->first << '\t' << itr->second << '\n';
    }

    cout << mp[1] <<"and"<< mp[2];

    vector<int> vec{ 1, 5, 9, 4, 3 };
    vector<int> res, res2;
    Solution sol;
    //res = sol.twoSum(vec, 9);
    res2 = sol.twoSum2(vec, 9, 0);

    return 0;
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
