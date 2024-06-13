// 253_Meeting_Room_2_interval.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
/* (0, 30) (5, 10) (15,20)
Key     Val
0       1
30      -1
5       1
10      -1
15      1
20      -1

0       1
5       1
10      -1
15      1
20      -1
30      -1*/
class Solution
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        map<int, int> mp;
        for (auto& i : intervals)
        {
            mp[i[0]]++;
            mp[i[1]]--;
        }
        int count = 0, maxCount = 0;
        for (auto& m : mp)
        {
            cout << m.first;
            count += m.second;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }

    int minMeetingRooms2(vector < vector<int>>& intervals)
    {
        map<int, int> mp;
        for (int i = 0; i < intervals.size(); i++)
        {
            mp[*intervals[i].begin()];
            mp[*intervals[i].end()];
        }
        int count = 0, maxCount = 0;
        map<int, int>::iterator m;
        for (m = mp.begin(); m != mp.end(); m++)
        {
            count += m->second;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    Solution sol;
    vector<vector<int>> interval {
        {0, 30},
        { 0, 10 },
        { 15, 20 }
    };
    int ans = sol.minMeetingRooms(interval);
    cout << ans;
    return ans;
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
