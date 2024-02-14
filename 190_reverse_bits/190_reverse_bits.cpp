// 190_reverse_bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        n = (n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16;
        n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8;
        n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4;
        n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2;
        n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1;
        return n;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    uint32_t num = 12345678;
    Solution sol;
    uint32_t ans = sol.reverseBits(num);
    cout << ans;
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
