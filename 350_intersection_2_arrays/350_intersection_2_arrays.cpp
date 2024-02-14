// 350_intersection_2_arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> map;
        if (nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }
        for (auto val : nums1)
        {
            map[val]++;
        }
        int id = 0;
        for (auto val : nums2)
        {
            if (map[val] > 0)
            {
                nums1[id++] = val;
                --map[val];
            }
            else
                break;
        }
        return vector<int>(nums1.begin(), nums1.begin()+id);
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums1{ 2, 5, 6, 8, 10 };
    vector<int> nums2{ 2, 5, 6, 9, 10 };
    Solution sol;
    vector<int> nums3 = sol.intersect(nums1, nums2);
    cout << "answer" << endl;
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
