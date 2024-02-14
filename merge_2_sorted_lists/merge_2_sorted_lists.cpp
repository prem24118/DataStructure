// merge_2_sorted_lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
//class Solution 
//{
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists)
//    {
//        size_t size = lists.size();
//        ListNode* merged = new ListNode();
//
//        //for (int i = 0; i < size; i++)
//        //{
//        //    lists[0]->val
//        //}
//        while (lists[0]->next != NULL || lists[1]->next != NULL)
//        {
//            if (lists[0]->val < lists[1]->val)
//            {
//                merged->val = lists[0]->val;
//                merged->next = lists[0]->next;
//                merged = merged->next; 
//                lists[0] = lists[0]->next;
//                
//            }
//            else if (lists[0]->val >= lists[1]->val)
//            {
//                merged->val = lists[1]->val;
//                merged->next = lists[1]->next;
//                merged = merged->next; 
//                lists[1] = lists[1]->next;
//                
//            }
//        }
//        return merged;
//    }
//    /*void insert(ListNode** head, int data)
//    {
//        if (*head == NULL)
//        {
//
//        }
//    }*/
//};

 class Solution {
 public:
     // this do the same work as merge function of merging two values
     ListNode* merge(ListNode* first, ListNode* second)
     {
         ListNode* result = NULL;

         if (first == nullptr)
             return second;

         if (second == nullptr)
             return first;


         if (first->val <= second->val)
         {
             result = first;
             result->next = merge(first->next, second);
         }
         else
         {
             result = second;
             result->next = merge(first, second->next);
         }
         return result;
     }
     ListNode* mergeKLists(vector<ListNode*>& arr) {
         int k = arr.size(); // extracting size of array
         if (k == 0) // if size of array is value
             return NULL;

         int start = 0; // start pointer
         int end = k - 1; // last pointer
         int temp;
         while (end != 0) // if last pointer not becomes zero
         {
             start = 0;
             temp = end;
             while (start < temp)
             {
                 // merge them and store in one of the linked list
                 arr[start] = merge(arr[start], arr[temp]);
                 start++; // increment start
                 temp--; // decrese start

                 if (start >= temp) // if at any point start passes the temp
                 {
                     end = temp;
                 }
             }
         }
         return arr[0]; // return first linked list of the aray as now it contains the all nodes in the sorted order.

     }
 };

int main()
{
   /* std::cout << "Hello World!\n";
    int numList1, numList2 = 0;
    cout << " Enter number of elements of the first list" << endl;
    cin >> numList1;
    cout << " Enter number of elements of the second list" << endl;
    cin >> numList2;

    cout << "Enter 1st list elements" << endl;*/
    ListNode* merged;
    Solution merging_class;
    ListNode* h1a = new ListNode(8);
    ListNode* h1d, *h1b, *h1c;
    h1b = new ListNode(6, h1a);
    h1c = new ListNode(4, h1b);
    h1d = new ListNode(2, h1a);

    ListNode* h2a, * h2b, * h2c, * h2d;
    h2a = new ListNode(7);
    h2b = new ListNode(5, h2a);
    h2c = new ListNode(3, h2b);
    h2d = new ListNode(1, h2a);

    ListNode* h3a, * h3b, * h3c, * h3d;
    h3a = new ListNode(5);
    h3b = new ListNode(5, h3a);
    h3c = new ListNode(3, h3b);
    h3d = new ListNode(3, h3a);

    ListNode* h4a, * h4b, * h4c, * h4d;
    h4a = new ListNode(6);
    h4b = new ListNode(5, h4a);
    h4c = new ListNode(3, h4b);
    h4d = new ListNode(4, h4a);

    vector<ListNode*> lists;
    lists.push_back(h1d);
    lists.push_back(h2d);
    lists.push_back(h3d);
    lists.push_back(h4d);

    merged = merging_class.mergeKLists(lists);

    do
    {
        cout << "merged val is" << merged->val;
        merged = merged->next;
    } while (merged != NULL);
    //ListNode




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
