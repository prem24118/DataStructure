// 124_bunarytree_maxpath_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    int res = INT16_MIN;
    int maxPathSum(TreeNode* root)
    {
        res = utility(root);
        return res;
    }
    int utility(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int left = utility(root->left);
        int right = utility(root->right);

        int temp = max(max(left, right) + root->val, root->val);
        int val = max(temp, left + right + root->val);
        res = max(res, val);
        return temp;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    TreeNode t1(1);
    TreeNode t3(3);
    TreeNode t2(2, &t1, &t3);
    TreeNode t7(7);
    TreeNode t5(5);
    TreeNode t6(6, &t5, &t7);
    TreeNode t4(4, &t2, &t6);
    Solution sol;
    int ans = sol.maxPathSum(&t4);
    cout << ans;
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
