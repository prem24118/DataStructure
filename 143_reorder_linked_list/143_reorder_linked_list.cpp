// 143_reorder_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* reorder = head;
        ListNode* halfnode = halfNode(head);
        halfnode = reverse(halfnode);
        while (reorder != NULL && halfnode != NULL && reorder != halfnode)
        {
            ListNode* temp1 = reorder->next;
            ListNode* temp2 = halfnode->next;
            reorder->next = halfnode;
            halfnode->next = temp1;
            reorder = temp1;
            halfnode = temp2;
        }
    }

    ListNode* halfNode(ListNode* head)
    {
        if (head == nullptr)
            return NULL;
        ListNode* slow = head, * fast = head;
        while (fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* previous, * current, * next;
        previous = NULL;
        current = head;
        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
        return head;
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
