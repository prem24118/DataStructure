// 101_Symettrictree_binarytree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)  {}
};

//symmetric means on the opposite ends they are equal; also value has to be equal
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        bool res = util(root->left, root->right);
        return res;
    }
    bool util(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL)
            return true;
        if ((left == NULL && right != NULL) || (left != NULL && right == NULL))
            return false;
        if (left->val == right->val)
        {
            return util(left->left, right->right) && util(left->right, right->left);
        }
        else
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
