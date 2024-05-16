// 226_invert_binarytree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Post order traversal

#include <iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    TreeNode* tree2 = new TreeNode(2);
    TreeNode* tree3 = new TreeNode(3);
    TreeNode* tree1 = new TreeNode(1, tree2, tree3);
    Solution sol;
    TreeNode* res;
    res = sol.invertTree(tree1);
    cout << "result" << res->val;
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
