// 692_top_frequent_common_words_string_xx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int> mp;
        map<int, string> mp2;
        set<pair<int, string>> st;
        vector<string> answer;
        for (auto& w : words)
        {
            mp[w]++;
        }
        for (auto& element : mp)
        {
            mp2[element.second] = element.first;
            st.insert(make_pair(element.second, element.first));
        }
        set<pair<int, string>>::reverse_iterator rit;
        pair<int, string> prev;
        int val = 0;
        for (rit = st.rbegin(); rit != st.rend(); rit++)
        {
            val++;
            if (prev.first != rit->first)
            {
                answer.push_back(rit->second);
            }
            else
            {
                if (rit->second < prev.second)
                {
                    answer.pop_back();
                    answer.push_back(rit->second);
                    answer.push_back(prev.second);
                }
                else
                    answer.push_back(rit->second);
            }
            prev = *rit;
        }
        return answer;
    }

    vector<string> topKFrequent2(vector<string>& words, int k)
    {
        map<string, int> mp;
        vector<string> ans;
        set<pair<int, string>> st;
        set<pair<int, string>>::reverse_iterator rit;
        pair<int, string> previous;
        if (words.size() > k)
        {
            for (auto& w : words)
            {
                mp[w]++;
            }
            for (auto& element : mp)
            {
                st.insert(make_pair(element.second, element.first));
            }
            int total = 0;
            for (rit = st.rbegin(); rit != st.rend(); rit++)
            {
                total++;
                if (total <= k)
                {
                    if (previous.first != rit->first)
                        ans.push_back(rit->second);
                    else
                    {
                        ans.pop_back();
                        ans.push_back(rit->second);
                        ans.push_back(previous.second);
                    }
                }
                previous = *rit;
            }
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
