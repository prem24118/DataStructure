// 1419_frog_croak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    int minNumberFrogs(string croaks)
    {
        map<char, int> frog;
        int count = 0;
        int total = 0;
        for (auto ch : croaks)
        {
            if (ch == 'c')
            {
                frog[ch]++;
                count++;
                total = max(count, total);
            }
            if (ch == 'r')
            {
                frog[ch]++;
                if (frog[ch] > frog['c'])
                    return -1;
            }
            if (ch == 'o')
            {
                frog[ch]++;
                if (frog[ch] > frog['r'])
                    return -1;
            }
            if (ch == 'a')
            {
                frog[ch]++;
                if (frog[ch] > frog['o'])
                    return -1;
            }
            if (ch == 'k')
            {
                frog[ch]++;
                count--;
                if (frog[ch] > frog['a'])
                    return -1;
            }
        }
        if (count != 0)
            return -1;
        return total;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution sol;
    string s = "crocrackoakroak";
    int ans = sol.minNumberFrogs(s);
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
