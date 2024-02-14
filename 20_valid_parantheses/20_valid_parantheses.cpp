// 20_valid_parantheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for (auto i : s)  //iterate over each and every elements
        {
            if (i == '(' or i == '{' or i == '[') st.push(i);  //if current element of the string will be opening bracket then we will just simply push it into the stack
            else  //if control comes to else part, it means that current element is a closing bracket, so check two conditions  current element matches with top of the stack and the stack must not be empty...
            {
                if (st.empty() or (st.top() == '(' and i != ')') or (st.top() == '{' and i != '}') or (st.top() == '[' and i != ']')) return false;
                st.pop();  //if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
        return st.empty();
    }

    bool isValid2(string s)
    {
        stack<char> st;
        for (auto i : s)
        {
            if (i == '(' || i == '{' || i == '[')
                st.push(i);
            else
            {
                if (st.empty() || i == ')' && st.top() != '(')
                    return false;
            }
        }
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
