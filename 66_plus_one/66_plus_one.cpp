// 66_plus_one.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int n = size(digits)-1;
        while (n >= 0)
        {
            if (digits[n] == 9)
                digits[n] = 0;
            else
            {
                digits[n] += 1;
                return digits;
            }
            n--;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
    vector<int> plusOne2(vector<int>& digits)
    {
        int size = digits.size();
        if (size > 0)
        {
            for (int i = size - 1; i >= 0; i--)
            {
                if (digits[i] < 9)
                {
                    digits[i]++;
                    return digits;
                }
                else
                {
                    digits[i] = 0;
                    //digits[i - 1]++;
                }
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vec{ 1, 9, 9 };
    vector<int> vec2;
    Solution sol;
    vec2 = sol.plusOne2(vec);
    cout << "val";
    vector<vector<int>> dp(3, vector<int>(8, 1));
    cout << "val2";
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
