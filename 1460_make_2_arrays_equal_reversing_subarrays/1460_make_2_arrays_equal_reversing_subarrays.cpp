// 1460_make_2_arrays_equal_reversing_subarrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool areTheyEqual(vector<int>& array_a, vector<int>& array_b) {
    // Write your code here
    int size1 = array_a.size();
    int size2 = array_b.size();
    unordered_map<int, int> count_map;
    if (size1 == size2)
    {
        for (auto x : array_a)
        {
            count_map[x]++;
        }
        for (auto x : array_b)
        {
            if (count_map[x] > 0)
            {
                count_map[x]--;
            }
            else
            {
                return false;
            }
        }
    }
    else
        return false;
    return true;
}

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
