#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution
{
private:
    const int inf = 0x3f3f3f3f;
    TreeNode* result = NULL;
    void LCA(TreeNode *root, TreeNode *A, TreeNode *B)
    {
        if (!root) return;
        bool foundA = 0, foundB = 0;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();

            if (cur == A) foundA = 1;
            if (cur == B) foundB = 1;

            if (foundA && foundB)
            {
                result = root;
                // cout << result->val << endl;
                LCA(root->left, A, B);
                LCA(root->right, A, B);
                return;
            }
            if (cur->left)  s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }
        return;
    }
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B)
    {
        LCA(root, A, B);
        return result;
    }
};

int main()
{
    /**
      *   3
      *  9  20
      *    15  7
      *  21 25
      */
    TreeNode *A = NULL, *B = NULL;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(21);
    root->right->left->right = new TreeNode(25);

    A = root->right->left;
    B = root->right->left->right;
    Solution sol;
    cout << sol.lowestCommonAncestor(root, A, B)->val;

    return 0;
}
