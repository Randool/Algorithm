// http://www.lintcode.com/zh-cn/problem/house-robber-iii/
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<TreeNode*, int> mti;
public:
    int houseRobber3(TreeNode * root) {
        if (root == NULL) return 0;
        if (mti[root] != 0) return mti[root];

        int pickRoot = root->val, notPickRoot;

        if (root->left) pickRoot += houseRobber3(root->left->left) + houseRobber3(root->left->right);
        if (root->right) pickRoot += houseRobber3(root->right->left) + houseRobber3(root->right->right);

        notPickRoot = houseRobber3(root->left) + houseRobber3(root->right);

        return mti[root] = max(pickRoot, notPickRoot);
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4), root->right = new TreeNode(5);
    root->left->left = new TreeNode(1), root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution sol;

    cout << sol.houseRobber3(root) << endl;

    return 0;
}
