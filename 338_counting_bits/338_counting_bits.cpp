// 338_counting_bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> answer;
        for (int i = 0; i <= n; i++)
        {
            int num = i;
            int sum = 0;
            while (num > 0)
            {
                sum += num % 2;
                num = num / 2;
            }
            answer.push_back(sum);
        }
        return answer;
    }

    vector<int> countBits2(int n)
    {
        vector<int> ans;
        int num = 0;
        int count = 0;
        for (int i = 0; i <= n; i++)
        {
            num = i;
            while (num > 0)
            {
                //this part is same as leetcode 191 with the couting 1 bits
                num = num & (num - 1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
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
