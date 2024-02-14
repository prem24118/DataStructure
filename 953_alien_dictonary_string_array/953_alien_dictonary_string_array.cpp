// 953_alien_dictonary_string_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int value[26] = { 0 };
        for (int i = 0; i < 26; i++)
        {
            value[order[i] - 'a'] = i;
        }
        for (auto& w : words)
        {
            for (auto& c : w)
            {
                c = value[c - 'a'];
                int bb = 10;
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<string> words = { "hello", "leetcode" };
    string order = { "hlabcdefgijkmnopqrstuvwxyz"};
    Solution sol;
    bool flag = sol.isAlienSorted(words, order);
    cout << endl;
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
