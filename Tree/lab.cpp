#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
}

class Solution {
public:
    /**
     * @param root: the root of tree
     * @return: the result node
     */
    TreeNode * maxNode(TreeNode * root) {
        // write your code here
        if (!root) return NULL;
        TreeNode *result = root;
        TreeNode *l = maxNode(root->left);
        TreeNode *r = maxNode(root->right);
        if (l && l->val > result->val) result = l;
        if (r && r->val > result->val) result = r;
        return result;
    }
};

class Solution {    // 507 ms
private:
    TreeNode *result = NULL;
    void search_max(TreeNode *root) {
        if (!root) return;
        if (root->val > result->val) result = root;
        search_max(root->left);
        search_max(root->right);
    }
public:
    TreeNode *maxNode(TreeNode *root) {
        if(root == NULL) return root;
        result = root;
        search_max(root);
        return result;
    }
};

int main() {

    return 0;
}
