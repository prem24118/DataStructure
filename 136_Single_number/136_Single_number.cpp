// 136_Single_number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> a;
		for (auto x : nums)
			a[x]++;
		for (auto z : a)
			if (z.second == 1)
				return z.first;
		return -1;
	}
	/*int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (auto x : nums)
			ans ^= x;
		return ans;
	}*/
	int singleNumber2(vector<int>& nums)
	{
		unordered_map<int, int> mp;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			mp[*it]++;
		}
		for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second = 1)
				return it->first;
		}
		return -1;
	}
};

int main()
{
    std::cout << "Hello World!\n";
	Solution sol;
	vector<int> doubles{ 2, 4, 6, 4, 6, 5, 5 };
	int out = sol.singleNumber(doubles);
	cout << out;
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
