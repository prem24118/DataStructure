// 104_max_depth_binary_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//check 100 for similar logic
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int outLeft = 1 + maxDepth(root->left);
        int outRight = 1 + maxDepth(root->right);
        return max(outLeft, outRight);
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
