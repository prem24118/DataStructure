// 242_valid_anagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> mp, mp2;
        for (auto elem : s)
        {
            mp[elem]++;
        }
        for (auto elem : t)
        {
            mp2[elem]++;
        }
        if (mp == mp2)
            return true;
        else
            return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    string s = "anagram";
    string t = "nagaram";
    Solution sol;
    bool ans = sol.isAnagram(s, t);
    cout << ans;
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
