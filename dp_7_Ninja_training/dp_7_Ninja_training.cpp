// dp_7_Ninja_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int ninjaUtil(int ind, int last, vector < vector<int>>& points, vector<vector<int>>& dp)
{
    if (ind == 0)
    {
        int maxVal = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxVal = max(maxVal, points[0][i]);
            }
        }
        return maxVal;
    }
    if (dp[ind][last] != -1)
        return dp[ind][last];

    int maxVal = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int activity = points[ind][i] + ninjaUtil(ind - 1, i, points, dp);
            maxVal = max(maxVal, activity);
        }
    }
    return dp[ind][last] = maxVal;
}
int ninjaTraining(int n, vector<vector<int>>& points)
{
    int col = points[0].size() + 1;
    vector<vector<int>> dp(n, vector<int>(col, -1));
    int ans = ninjaUtil(n-1, 3, points, dp);
    return ans;
}

int ninjaTraining2(int n, vector<vector<int>>& points)
{
    vector<vector<int>> dp;
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], points[0][1], points[0][2]);

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 3; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    return dp[n][3];

}
int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> points = { {10, 40, 70}, {20, 50, 80}, {30, 60, 90} };
    int n = points.size();
    cout << ninjaTraining(n, points);
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
