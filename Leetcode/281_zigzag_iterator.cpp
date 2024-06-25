// Leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() != 0)
        {
            Q.push(make_pair(v1.begin(), v1.end()));
        }
        if (v2.size() != 0)
        {
            Q.push(make_pair(v2.begin(), v2.end()));
        }

    }

    int next() {
        vector<int>::iterator it = Q.front().first;
        vector<int>::iterator endit = Q.front().second;
        Q.pop();
        if (it + 1 != endit)
        {
            Q.push(make_pair(it + 1, endit));
        }
        return *it;
    }

    bool hasNext() {
        return !Q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;
};

class ZigzagIterator2
{
public:
    ZigzagIterator2(vector<int> v1, vector<int> v2)
    {
        if (v1.size() != 0)
        {
            q.push(make_pair(v1.begin(), v1.end()));
        }
        if (v2.size() != 0)
        {
            q.push(make_pair(v2.begin(), v2.end()));
        }
    }
    bool hasNext()
    {
        if (!q.empty())
            return true;
        else
            return false;
    }
    int next()
    {
        vector<int>::iterator it = q.front().first;
        vector<int>::iterator endit = q.front().second;
        q.pop();
        if (it + 1 != endit)
        {
            q.push(make_pair(it + 1, endit));
        }
        return *it;
    }
private:
    queue < pair<vector<int>::iterator, vector<int>::iterator> > q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
    std::cout << "Hello World!\n";

    vector<int> v1 = { 2, 5, 6 }, v2 = { 3, 4, 7 };
    ZigzagIterator i(v1, v2);
    while (i.hasNext())
    {
        cout << i.next();
    }
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
