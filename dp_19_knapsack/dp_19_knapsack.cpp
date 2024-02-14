// dp_19_knapsack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int target, vector<vector<int>>& dp)
{
    if (ind == 0)
    {
        if (wt[0] <= target)
        {
            return val[0];
        }
        else
            return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notTake = 0 + knapsackUtil(wt, val, ind - 1, target, dp);
    int take = INT_MIN;
    if (wt[ind] <= target)
    {
        take = val[ind] + knapsackUtil(wt, val, ind - 1, target - wt[ind], dp);
    }
    return dp[ind][target] = max(take, notTake);
}

int knapsack(vector<int>& wt, vector<int>& val, int n, int target)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return knapsackUtil(wt, val, n - 1, target, dp);
}

int knapsack2(vector<int>& wt, vector<int>& val, int n, int targetWeight)
{
    //int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(targetWeight + 1, 0));
    for(int weight = wt[0]; weight <= targetWeight; weight++)
    {
        dp[0][weight] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (auto weight = 0; weight <= targetWeight; weight++)// wt)
        {
            int notTake = 0 + dp[ind - 1][weight];
            int take = INT_MIN;
            if (wt[ind] <= weight)
            {
                take = val[ind] + dp[ind - 1][weight - wt[ind]];
            }
            dp[ind][weight] = max(take, notTake);
        }
    }
    return dp[n - 1][targetWeight];
}


int main()
{
    //std::cout << "Hello World!\n";
    vector<int> wt{1, 2, 4, 5};
    vector<int> val = { 50, 40, 80, 60 };
    int W = 5;
    int n = wt.size();
    int maxval = knapsack2(wt, val, n, W);
    cout << "max value thief can steal is" << maxval;
    cout << endl << "end";
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
