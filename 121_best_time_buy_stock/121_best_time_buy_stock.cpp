// 121_best_time_buy_stock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
//this one differs from 122 in that its only buy and sell the stock once, vs 122 you can buy and sell any number of times
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int highest_profit = INT16_MIN;
        int lowest_price = INT16_MAX;
        int size = prices.size();
        if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                if (prices[i] < lowest_price)
                    lowest_price = prices[i];
                if (highest_profit < prices[i] - lowest_price)
                {
                    highest_profit = prices[i] - lowest_price;
                }
            }
        }
        return highest_profit;
    }

    int maxProfit2(vector<int>& price)
    {
        int size = price.size();
        int highest_profit = INT_MIN;
        int lowest_price = INT_MAX;
        for (int i = 0; i < size; i++)
        {
            if (price[i] < lowest_price)
                lowest_price = price[i];
            if (highest_profit > price[i] - lowest_price)
                highest_profit = price[i] - lowest_price;
        }
        return highest_profit;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    vector<int> vec{ 4, 1, 8, 5, 3, 9 };
    Solution sol;
    int profit = sol.maxProfit(vec);
    cout << "the profit is" << profit;
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
