// 179_largest_number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//using namespace std;
class Solution
{
public:
    static bool comp(const std::string& s1, const std::string& s2)
    {
        return s1 + s2 > s2 + s1;
    }
    std::string largestNumber(std::vector<int>& num)
    {
        std::vector<std::string> arr;
        std::string numbers;
        for (auto i : num)
        {
            arr.push_back(std::to_string(i));
        }
        sort(arr.begin(), arr.end(), comp);
        for (auto s : arr)
        {
            numbers += s;
        }
        while (numbers[0] == '0' && numbers.size() > 1)
            numbers.erase(0, 1);
        return numbers;
    }
    
};

int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> vec = { 34, 89, 7, 0, 4, 92 };
    Solution sol;
    std::string s = sol.largestNumber(vec);
    std::cout << s;
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
