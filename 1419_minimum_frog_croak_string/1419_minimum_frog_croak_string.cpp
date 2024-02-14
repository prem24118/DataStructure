// 1419_minimum_frog_croak_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        map<char, int> frog;
        for (auto ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                frog[ch]++;
            }
            if (ch == 'r')
            {
                frog[ch]++;
            }
            if (ch == 'o')
            {
                frog[ch]++;
            }
            if (ch == 'a')
            {
                frog[ch]++;
            }
            if (ch == 'k')
            {
                frog[ch]++;
            }
        }
        int count = frog['c'];
        for (auto elem : frog)
        {
            if (elem.second != count)
                return -1;
            else continue;
        }
        return count;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution sol;
    string str = "croakcroak";
    int ans = sol.minNumberOfFrogs(str);
    cout << ans;
    return ans;
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
