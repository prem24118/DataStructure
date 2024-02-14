// 191_number_of_1_bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    int hammingWeight2(uint32_t n)
    {
        if (n)
        {
            return 1 + hammingWeight2(n & (n - 1));
        }
        else
            return 0;

    }
    int hammingWeight3(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            if (n & 1)
                count++;
            n = n >> 1;
        }
        return count;
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
