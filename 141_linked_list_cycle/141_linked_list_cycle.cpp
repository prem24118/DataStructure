// 141_linked_list_cycle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode* next;
public:
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val (x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* slow = head, * fast = head;
        while (fast != 0)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }
        return false;
    }

    bool hasCycle2(ListNode* head)
    {
        unordered_set<ListNode*> st;
        if (head == NULL)
            return false;
        ListNode* dummy = head;
        while (dummy != NULL)
        {
            if (st.find(dummy) != st.end())
                return true;
            st.insert(dummy);
            dummy = dummy->next;
        }
        return false;
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
