// 234_palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class ListNode
{
public:
    int value;
    ListNode* next;
    ListNode() : value(0), next(NULL) {}
    ListNode(int x) : value(x), next(NULL) {}
    ListNode(int x, ListNode* node) : value(x), next(node) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* copynode = head;
        bool flag = false;

        ListNode* halfnode = getHalf(head);
        halfnode = reverse(halfnode);

        while (head != NULL && halfnode != NULL)
        {
            if (head->value == halfnode->value)
            {
                head = head->next;
                halfnode = halfnode->next;
            }
            else
                return flag;
        }
        flag = true;
        return flag;
    }

    ListNode* reverse(ListNode* node)
    {
        ListNode* current, * previous, * next;
        previous = NULL;
        current = node;
        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        node = previous;
        return node;
    }

    ListNode* getHalf(ListNode* node)
    {
        ListNode *slow = node, *fast = node;
        while (fast)
        {
            if (fast->next && fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            else
            {
                if (fast->next)
                    slow = slow->next;
                break;
            }
            
        }
        return slow;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    ListNode node1(1);
    ListNode node2(2, &node1);
    ListNode node3(2, &node2);
    ListNode node4(1, &node3);
    Solution sol;
    bool out = sol.isPalindrome(&node4);
    cout << "answer";

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
