// 22_generate_paranthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> generateParanthesis(int n)
    {
        vector<string> para;
        string s = "";
        helper(n, n, para, s);
        return para;
    }
    void helper(int open, int close, vector<string>& para, string s)
    {
        if (open == 0 && close == 0)
        {
            cout << s << endl;
            para.push_back(s);
            return;
        }
        if (open > 0)
        {
            cout << s<<endl;
            helper(open - 1, close, para, s + '(');
        }
        if (close > 0 && close > open)
        {
            cout << s<< endl;
            helper(open, close - 1, para, s + ')');
        }
    }
};
int main()
{
    std::cout << "Hello World!\n";
    Solution sol;
    sol.generateParanthesis(2);
    cout << "Final";
    return 0;
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
