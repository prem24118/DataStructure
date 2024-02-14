// Recursion_printing_subarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int printS(int ind, vector<int>& ds, int s, int sumtotal, vector<int>& arr, int n)
    {
        if (ind == n)
        {
            if (s == sumtotal)
            {
                for (auto it : ds)
                {
                    cout << it << " " << endl;
                }
                return 1;
            }
            else return 0;
        }
        s += arr[ind];
        ds.push_back(arr[ind]);
        int l = 0;
        l = printS(ind + 1, ds, s, sumtotal, arr, n);
            //return true;
        s -= arr[ind];
        ds.pop_back();
        int r = 0;
        r = printS(ind + 1, ds, s, sumtotal, arr, n);
            //return true;
        return l + r;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vec{ 1,2 ,5 };
    vector<int> ds;
    int sum = 9;
    Solution sol;
    int flag = sol.printS(0, ds, 0, sum, vec, vec.size());
    cout << flag;
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
