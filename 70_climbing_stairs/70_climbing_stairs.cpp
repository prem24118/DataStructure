// 70_climbing_stairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution
{
public:

    int climbStairs(int n)
    {
        int *memo = new int[n+1];
        int x = climbstairs(n, n, memo);
        return x;
    }
    int climbstairs(int i, int n, int memo[])
    {
        //recurssion is similar to decode ways or fibonacci with the difference being 
//the condition
        if (i < 0)
        {
            return 0;
        }
        if (i == 0)
        {
            return 1;
        }
        if (memo[i] > 0)
        {
            return memo[i];
        }
        memo[i] = climbstairs(i - 1, n, memo) + climbstairs(i - 2, n, memo);
        return memo[i];
    }
    /*One can reach the ith step in 1 of 2 ways
    1. Taking a single step from (i-1)th step
    2. taking 2 steps from (i-2)th step
    So number of ways to reach ith step is sum of 
    ways of reaching i-1 step and sum of ways of reaching i-2 step */
    /*int climbStairs(int n)
    {
        int* dp = new int[n];
        if (n == 1)
            return 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }*/
};

int main()
{
    std::cout << "Hello World!\n";
    Solution sol;
    int x =sol.climbStairs(4);
    cout << x;
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
