// 252_meeting_room_interval.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        for (int i = 0; i < size - 1; i++)
        {
            if (intervals[i][1] <= intervals[i + 1][0])
                continue;
            else
                return false;
        }
        return true;
    }

    static bool comp(vector<int> v1, vector<int> v2)
    {
        return v1[0] < v2[0];
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int> > vect{ { 3, 5 },
        { 4, 8 },
        { 7, 9 } };
    Solution* sol = new Solution;
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
