#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		unordered_map<int, int> mp;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			mp[nums[i]]++;
		}
		n = n / 2;
		for (auto elem : mp)
		{
			if (elem.second > n)
				return elem.first;
		}
		return 0;
	}
};

int main()
{
	Solution sol;
	vector<int> nums {1, 3, 3};
	int ans = sol.majorityElement(nums);
	cout << ans;
}