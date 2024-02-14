// 122_best_time_buy_stock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        int peak = 10000;
        int valley = peak;
        int size = prices.size();
        if (size > 1)
        {
            peak = prices[0];
            valley = prices[0];
            for (int i = 0; i < size; i++)
            {
                if (peak < prices[i])
                {
                    peak = prices[i];
                }
                else if (peak >= prices[i])
                {
                    total += (peak - valley);
                    peak = prices[i];
                    valley = prices[i];
                }
            }
            total += (peak - valley);
            return total;
        }
        else
            return 0;
    }
    //Neater solution
   /* int maxProfit(vector<int>& prices) {
        int ans = 0, i = 0, n = prices.size() - 1;
        for (; i < n; i++) {
            ans += max(prices[i + 1] - prices[i], 0);
        }
        return ans;
    }*/
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums {2, 4, 1, 9, 7, 6, 0, 10};
    Solution sol;
    sol.maxProfit(nums);
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
