// 366_leaves_of_binary_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Post order

#include <iostream>
#include <vector>
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
    vector<vector<int>> findLeaves(TreeNode* root)
    {
        vector<vector<int>> res;
        util(root, res);
        return res;
    }
private:
    int util(TreeNode* root, vector<vector<int>>& res)
    {
        if (root == nullptr)
            return 0;
        int level;
        int leftmax = util(root->left, res);
        int rightmax = util(root->right, res);
        cout << "leftmax: " << leftmax << " right max: " << rightmax;
        level = max(leftmax, rightmax) + 1;
        cout << "level " << level << endl;
        if (level > res.size())
        {
            res.push_back(vector<int>());
        }
        res[level - 1].push_back(root->val);
        cout << "root val " << root->val << endl;
        return level;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    TreeNode* root4 = new TreeNode(4);
    TreeNode* root5 = new TreeNode(5);
    TreeNode* root2 = new TreeNode(2, root4, root5);
    TreeNode* root3 = new TreeNode(3);
    TreeNode* root1 = new TreeNode(1, root2, root3);
    Solution sol;
    vector<vector<int>> ans;
    ans = sol.findLeaves(root1);
    for (auto a : ans)
    {
        for (auto element : a)
        {
            cout << element << " ";
        }
        cout << "\n";
    }

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
