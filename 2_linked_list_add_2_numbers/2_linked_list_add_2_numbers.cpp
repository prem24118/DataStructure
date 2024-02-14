// 2_linked_list_add_2_numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* reshead = new ListNode(0);
        ListNode* result = reshead;
        int res = 0 , sum = 0, carry = 0;
        while (l1 || l2 || carry)
        {
            sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            //either point to the 2nd elemnt from head because 1st node val is 0 
            //or check to see of there is a carry  and if so mak another node, if not dont make one
            res = sum % 10;
            carry = sum / 10;
            result->next = new ListNode(res);
            result = result->next;
            //or
            /*result->val = res;
            if (l1 || l2 || carry)
            {
                result->next = new ListNode(0);
                result = result->next;
            }*/
        }
        return reshead->next;
        //or 
        //return reshead;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(2, node1);
    ListNode* node3 = new ListNode(2, node2);
    ListNode* node4 = new ListNode(2, node3);


    ListNode another1(9);
    ListNode another2(9, &another1);
    ListNode another3(9, &another2);
    Solution sol;
    ListNode* result = sol.addTwoNumbers(node3, &another3);
    while (result != nullptr)
    {
        cout << result->val<<endl;
        result = result->next;
    }
    cout << endl;
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
