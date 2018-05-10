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

class BSTIterator {
private:
    TreeNode* cur = NULL;
    stack<TreeNode*> stack_;
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return (cur || !stack_.empty());
    }

    //@return: return next node
    TreeNode* next() {
        while (cur) {
            stack_.push(cur);
            cur = cur->left;
        }
        cur = stack_.top();
        stack_.pop();
        TreeNode* node = cur;
        cur = cur->right;

        return node;
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

	BSTIterator BST_iter(root);
    while (BST_iter.hasNext())
    {
        cout << BST_iter.next()->val << endl;
    }

	return 0;
}
