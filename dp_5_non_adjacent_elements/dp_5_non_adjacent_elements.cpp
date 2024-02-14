// dp_5_non_adjacent_elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int solveUtil(int ind, vector<int>& arr, vector<int>& dp)
{
    if (ind == 0)
        return arr[0];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int notTake = 0 + solveUtil(ind - 1, arr, dp);
    int take = arr[ind] + solveUtil(ind - 2, arr, dp);
    return dp[ind] = max(take, notTake);
}

int solve(int n, vector<int>& arr)
{
    vector<int> dp(n, -1);
    int ans = solveUtil(n-1, arr, dp);
    return ans;
}

int solve2(int n, vector<int>& arr)
{
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int ind = 1; ind < n; ind++)
    {
        int notTake = 0 + dp[ind - 1];
        int take = INT_MIN;
        if(ind > 1)
            take = arr[ind] + dp[ind - 2];
        dp[ind] = max(take, notTake);
    }
    return dp[n - 1];
}

int main()
{
    std::cout << "Hello World!\n";
    vector<int> arr = { 2, 1, 4, 9 };
    int n = arr.size();
    cout << solve2(n, arr);
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
