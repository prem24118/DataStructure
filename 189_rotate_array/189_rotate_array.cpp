// 189_rotate_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int size = nums.size();
        if (k > size)
        {
            k = k % size;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }

    /*void rotate(vector<int>& nums, int k)
    {
        int size = nums.size();
        if (k > size)
        {
            k = k % size;
        }
        int location = size - k;
        vector<int> rot(nums.end() - k, nums.end());
        for (int i = 0; i < location; i++)
        {
            rot.push_back(nums[i]);
        }
        nums = rot;
    }*/
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> rev{ 1, 2, 3, 4, 5, 6, 7 };
    Solution sol;
    int k = 2;
    sol.rotate(rev, k);
    cout << rev[0];
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
