// 322_coin_change.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount+1, INT16_MAX);
        if (n < 1)
            return 0;
        dp[0] = 0;
        for (auto coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[amount] <= amount)
        {
            return dp[amount];
        }
        else
            return -1;
    }
    
    int coinChangeUtil(vector<int>& coins, int amount, int index, vector<int>& memo)
    {
        if (amount == 0)
            return 1;
        if (amount < 0 || index >= coins.size())
            return 0;
        if (memo[amount] != 0)
            return memo[amount];

        int total = 0;
        for (int i = index; i < coins.size(); i++)
        {
            int coin = coins[i];
            int remainder = amount - coin;
            total += coinChangeUtil(coins, remainder, i, memo);
            memo[amount] = total;
        }

       
        return total;
    }

    int coinChange2(vector<int>& coins, int amount)
    {
        int res = findLowestCoins(coins, 0, amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }

    int findLowestCoins(vector<int>& coins, int cur, int amount)
    {
        if (cur >= coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;

        int res = -1;
        if (coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = min(takeCoin, doNotTakeCoin);
        }
        return res;
    }
    //Striver

    int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp) {

        if (ind == 0) {
            if (T % arr[0] == 0) return T / arr[0];
            else return 1e9;
        }

        if (dp[ind][T] != -1)
            return dp[ind][T];

        int notTaken = 0 + minimumElementsUtil(arr, ind - 1, T, dp);

        int taken = 1e9;
        if (arr[ind] <= T)
            taken = 1 + minimumElementsUtil(arr, ind, T - arr[ind], dp);

        return dp[ind][T] = min(notTaken, taken);
    }


    int minimumElements(vector<int>& arr, int T) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(T + 1, -1));
        int ans = minimumElementsUtil(arr, n - 1, T, dp);
        if (ans >= 1e9) return -1;
        return ans;
    }

    int coinChangeTabulation(vector<int>& arr, int target)
    {
        int size = arr.size();
        vector<vector<int>> dp(size, vector<int>(target, -1));
        /*if ()
        {

        }*/
        for (int ind = 1; ind < size; ind++)
        {
            for (int tar = target; tar >= 0; tar--)
            {
                int notTake = 0 + dp[ind - 1][tar];
                int take = 0;
                if (arr[ind] < tar)
                    take = 1 + dp[ind][tar - arr[ind]];
                dp[ind][tar] = min(take, notTake);
            }
        }
        return dp[size - 1][target];
    }

    int cc(vector<int>& coins, int amount)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount, -1));
        int total = ccUtil(coins, dp, amount, 0);
        return total;
    }
    int ccUtil(vector<int>& coins, vector<vector<int>>& dp, int amount, int index)
    {
        int notTake = 0 + ccUtil(coins, dp, amount, index + 1);
        int take = 0;
        if (amount > coins[index])
        {
            take = 1 + ccUtil(coins, dp, amount - coins[index], index);
        }
        return dp[index][amount] = min(take, notTake);
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vec{ 1, 2 };
    int amount = 4;
    Solution sol;
    int total = sol.minimumElements(vec, amount);
    cout << total;

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
