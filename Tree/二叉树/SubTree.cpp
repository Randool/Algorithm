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
    bool isSameTree(TreeNode* T1, TreeNode* T2)
    {
        if (T1 == NULL && T2 == NULL) return 1;
        if (T1 == NULL || T2 == NULL) return 0;
        if (T1->val != T2->val) return 0;
        return isSameTree(T1->left, T2->left) && isSameTree(T1->right, T2->right);
    }
public:
    bool isSubtree(TreeNode *T1, TreeNode *T2)
    {
        if (T2 == NULL) return 1;
        else if (T1 == NULL) return 0;
        else return isSameTree(T1, T2) || isSameTree(T1->left, T2) || isSameTree(T1->right, T2);
    }
};

int main()
{
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    A->right->left = new TreeNode(4);

    TreeNode* B = new TreeNode(3);
    B->right = new TreeNode(4);

    Solution sol;
    if (sol.isSubtree(A,B))
        puts("True");
    else
        puts("False");

    return 0;
}
