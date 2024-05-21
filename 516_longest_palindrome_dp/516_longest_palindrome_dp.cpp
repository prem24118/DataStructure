// 516_longest_palindrome_dp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestPanlindromeSubseq(string s)
    {

        //reason for going from n - 1 to 0 is because we want the final output dp to be the last one computed
        //if not and is the first row, the conditions will not get the next row value correctly, need to get all values before computing final value
        //      0   1   2   3   4
        // 
        // 0    1   2   3   3   2 (this should be 4)
        // 1    0   1   2   2   3
        // 2    0   0   1   1   3 
        // 3    0   0   0   1   1
        // 4    0   0   0   0   1
        //
        //instead we need to do this byt going n - 1 to 0 so that dp[n-1][n-1] has the right value
        //
        //      0   1   2   3   4
        // 
        // 4    0   0   0   0   1 
        // 3    0   0   0   1   1
        // 2    0   0   1   1   3
        // 1    0   1   2   2   3
        // 0    1   2   3   3   4
        //
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> value;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = i+1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //diagonal because that is the element which is between the 2 far right and left elments
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            value.push_back(*max_element(dp[i].begin(), dp[i].end()));
        }
        return *max_element(value.begin(), value.end());

        //for (int i = 0; i < s.size(); i++)
        //{
        //    value.push_back(*max_element(dp[i].begin(), dp[i].end()));
        //}
        //return *max_element(value.begin(), value.end());
    }
    //int longestPanlindromeSubseq(string s)
    //{
    //    char left = s[0];
    //    char right = s[s.size() - 1];
    //    util(left, right, s);
    //}
    //int util(char left, char right, string& s)
    //{
    //    if (left == right)
    //        return 1;

    //}
};

int main()
{
    //std::cout << "Hello World!\n";
    Solution sol;
    string str = { "bbbab" };
    int ans = sol.longestPanlindromeSubseq(str);
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
