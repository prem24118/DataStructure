// 91_decode_ways_dp_recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        int ans = util(s, 0);
        return ans;
    }
    int util(string& s, int num)
    {
        if (s.size() == num)
            return 1;
        if (s[num] == '0')
            return 0;
        int result = 0;
        //recurssion is similar to climbing stairs or fibonacci with the difference being 
        //the condition

        result += util(s, num + 1);
        if (num < s.size() && (s[num] == '1' || (s[num] == '2' && s[num + 1] <= 6)))
            result += util(s, num + 2);

        return result;
    }

    int util2(string& s, int num, vector<int> memo)
    {
        int n = s.size();
        if (n == num)
        {
            return 1;
        }
        if (s[num] == '0')
        {
            return 0;
        }
        if (memo[num] != -1)
            return memo[num];
        int answer;
        answer = util(s, num + 1);
        if (num < s.size() && (s[num] == '1' || (s[num] == '2' && s[num + 1] < '7')));
        {
            answer += util(s, num + 2);
        }
        memo[num] = answer;
        return memo[num];
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
