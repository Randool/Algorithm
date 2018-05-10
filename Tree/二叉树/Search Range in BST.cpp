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
};

class Solution {
private:
    TreeNode *cur = NULL;
    vector<int> result;
    void inorder(TreeNode* root, int k1, int k2)
    {
        if (!root) return;
        if (root->val > k1 && root->left) inorder(root->left, k1, k2);
        if (root->val >= k1 && root->val <= k2)result.push_back(root->val);
        if (root->val < k2 && root->right) inorder(root->right, k1, k2);
    }
public:
	vector<int> searchRange(TreeNode* root, int k1, int k2) {
        inorder(root, k1, k2);
        return result;
    }
};

int main() {
	/*
	     20
	    8  22
      4  12
	*/
	TreeNode* root = new TreeNode(20);
	root->left = new TreeNode(8);
	root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);

	Solution sol;
    vector<int> vals = sol.searchRange(root, 10, 22);
    for (int i=0; i<vals.size(); ++i)
        cout << vals[i] << " ";

	return 0;
}
