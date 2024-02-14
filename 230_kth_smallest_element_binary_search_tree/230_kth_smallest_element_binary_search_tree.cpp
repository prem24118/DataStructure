// 230_kth_smallest_element_binary_search_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class TreeNode
{
public:

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};
class Solution
{
public:
    int res = 0;
    int ans;
    int kthSmallest(TreeNode* root, int& k)
    {
        util(root, k);
        return ans;
    }
    void util(TreeNode* root, int k)
    {
        if (root == nullptr)
            return;
            
        util(root->left, k);
        res++;
        if (res == k)
        {
            ans =  root->val;
            return;
        }
        util(root->right, k);
        
    }
};

int main()
{
    std::cout << "Hello World!\n";
    TreeNode* node1 = new TreeNode(40);
    TreeNode* node2 = new TreeNode(60);
    TreeNode* node3 = new TreeNode(50, node1, node2);

    TreeNode* node4 = new TreeNode(70);
    TreeNode* node5 = new TreeNode(90);
    TreeNode* node6 = new TreeNode(80, node4, node5);

    TreeNode* node7 = new TreeNode(55, node3, node6);
    Solution sol;
    int k = 6;
    int ans = sol.kthSmallest(node7, k);
    cout << "ans";
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
