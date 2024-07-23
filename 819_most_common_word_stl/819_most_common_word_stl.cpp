// 819_most_common_word_stl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
using namespace std;
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        
        set<string> banned_set(banned.begin(), banned.end());
        map<string, int> mp;
        vector<string> non_banned_words;
        string words;
        string answer;
        int total = 0;
        for (auto& w : paragraph)
        {
            if (isalpha(w))
                w = tolower(w);
            else
                w = ' ';
        }
        istringstream iss(paragraph);
        while (iss >> words)
        {
            if (banned_set.find(words) != banned_set.end())
                continue;
            else
            {
                mp[words]++;
                //non_banned_words.push_back(words);
            }
        }
        //for (auto& word : non_banned_words)
        //{
        //    if (mp[word] > total)
        //    {
        //        total = mp[word];
        //        answer = word;
        //    }
        //}
        for (auto& element : mp)
        {
            if (element.second > total)
            {
                total = element.second;
                answer = element.first;
            }
        }
        return answer;
    } 

    string mostCommonWord2(string paragraph, vector<string>& banned)
    {
        for (auto& w : paragraph)
        {
            if (isalpha(w))
                w = tolower(w);
            else
                w = ' ';
        }
        istringstream iss(paragraph);
        map<string, int> mp;
        set<string> banned_set(banned.begin(), banned.end());
        string word;
        string answer;
        while (iss >> word)
        {
            if (banned_set.find(word) != banned_set.end())
            {
                continue;
            }
            else
            {
                mp[word]++;
            }
        }
        int count = 0;
        for (auto& element : mp)
        {
            int total = element.second;
            if (count < total)
            {
                count = total;
                answer = element.first;
            }
        }
        return answer;
    }

    string mostCommonWord3(string paragraph, vector<string>& banned)
    {
        map<string, int> mp;
        for (auto elem : paragraph)
        {
            if (isalpha(elem))
                elem = tolower(elem);
            else
                elem = ' ';
        }
        istringstream iss(paragraph);
        string words;
        set<string> banned_set(banned.begin(), banned.end());
        while (iss >> words)
        {
            if (banned_set.find(words) != banned_set.end())
                continue;
            else
            {
                mp[words]++;
            }
        }
        int count = 0;
        for (auto elem : mp)
        {
            count = max(count, elem.second);
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
    string input = "Bob hit a ball, the hit BALL flew far after it was hit";
    Solution sol;
    vector<string> banned = { "hit" };
    string ans = sol.mostCommonWord(input, banned);
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
