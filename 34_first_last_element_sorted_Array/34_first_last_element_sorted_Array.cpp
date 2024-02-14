// 34_first_last_element_sorted_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<int> answer;
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                answer.push_back(i);
            }
        }
        if (answer.empty())
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        else
        {
            int max_ele = *max_element(answer.begin(), answer.end());
            int min_ele = *min_element(answer.begin(), answer.end());
            result.push_back(min_ele);
            result.push_back(max_ele);
        }
        return result;
    }

    vector<int> searchRange2(vector<int>& nums, int target)
    {
        //Binary search method
        /*Therefore, the block else { e = m - 1; ans[0] = m - 1; } 
        will be hit when the binary search finds the target element, 
        but it is not the first occurrence of the target in the array a. 
        It updates the variables e and ans[0] to continue searching 
        for the first occurrence in the left half of the remaining range.*/
        int start = 0, end = nums.size() - 1, mid;
        vector<int> ans(2, -1);
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                if (mid == start || nums[mid] != nums[mid - 1])
                {
                    ans[0] = mid;
                    break;
                }
                else
                {
                    end = mid - 1;
                    ans[0] = mid - 1;
                }
            }
        }
        /*Therefore, the block else { s = m + 1; ans[1] = m + 1; } 
        will be hit when the binary search finds the target element, 
        but it is not the last occurrence of the target in the array a. 
        It updates the variables s and ans[1] to continue searching 
        for the last occurrence in the right half of the remaining range.*/
        start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                if (mid == end || nums[mid] != nums[mid + 1])
                {
                    ans[1] = mid;
                    break;
                }
                else
                {
                    start = mid + 1;
                    ans[1] = mid + 1;
                }
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
