// 26_remove_duplicates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& arr)
    {
        int size = arr.size();
        int position = 0;
        int currentVal = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            if (currentVal != arr[i])
            {
                currentVal = arr[i];
                arr[position++] = currentVal;
                //position += 1;
            }
            else
            {
                continue;
            }
        }
        return position;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums { 1, 1, 1, 5, 5, 20, 50 };
    int k = 0;
    Solution sol;
    k = sol.removeDuplicates(nums);
    cout << k;
    //vector<int>::iterator it;
    //    for (it = nums.begin(); it !=nums.end(); it++)
    //    {
    //        //cout << "1 " << *it << endl;
    //        //cout << "2 " << *(it+1) << endl; 
    //        if ((*it == *(it + 1)) && *it !=0)
    //        {
    //            k++;
    //            nums.erase(it+1);
    //            nums.push_back(0);
    //        }
    //    }
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
