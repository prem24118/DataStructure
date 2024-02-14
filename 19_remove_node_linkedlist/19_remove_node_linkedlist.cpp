// 19_remove_node_linkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) { }
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* right = head;
        ListNode* left = head;
        for (int i = 0; i <= n; i++)
        {
            if (right == NULL)
                return head->next;
            right = right->next;
        }
        while (right != NULL)
        {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return head;
    }
    void deleteNode(ListNode* node)
    {
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    ListNode* node1 = new ListNode(11);
    ListNode* node2 = new ListNode(10, node1);
    ListNode* node3 = new ListNode(9, node2);
    ListNode* node4 = new ListNode(8, node3);


    ListNode another1(4);
    ListNode another2(3, &another1);
    ListNode another3(2, &another2);

    Solution sol;
    ListNode * res1 = sol.removeNthFromEnd(node4, 4);
    ListNode * res2 = sol.removeNthFromEnd(&another3, 3);
    cout << "values are";
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
