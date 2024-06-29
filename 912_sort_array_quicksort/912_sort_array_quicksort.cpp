// 912_sort_array_quicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
    void qs(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return;
        int pivot = partition(nums, left, right);
        qs(nums, left, pivot - 1);
        qs(nums, pivot + 1, right);
    }
    int partition(vector<int>& nums, int l, int r)
    {
        int pivotVal = nums[r];
        int i = l - 1, j;
        for (j = l; j < r; j++)
        {
            if (nums[j] < pivotVal)
            {
                i = i + 1;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        i = i + 1;
        int temp = nums[i];
        nums[i] = nums[r];
        nums[r] = temp;
        return i;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vec = { 3, 8, 2, 0, 4 };
    vector<int> ans;
    Solution sol;
    ans = sol.sortArray(vec);
    cout << "sorted";
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
