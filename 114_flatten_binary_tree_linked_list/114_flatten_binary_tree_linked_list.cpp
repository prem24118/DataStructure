// 114_flatten_binary_tree_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class TreeNode
{
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode* next = nullptr;
    void flatten(TreeNode*& root)
    {
        if (root == nullptr)
        {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = next;
        next = root;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    TreeNode* tree2 = new TreeNode(2);
    TreeNode* tree3 = new TreeNode(3);
    TreeNode* tree1 = new TreeNode(1, tree2, tree3);
    Solution sol;
    sol.flatten(tree1);
    std::cout << std::endl;
    return 0;
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
