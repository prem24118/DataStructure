// 88_merge_sorted_arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= n)
        {
            if (nums1[i] <= nums2[j])
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            else
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        while (i >= 0)
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }

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
