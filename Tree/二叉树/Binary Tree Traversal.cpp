// http://www.lintcode.com/en/problem/binary-tree-preorder-traversal/
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorder1(TreeNode *root) {
        // 递归实现先序遍历
        vector<int> result;
        if (root)
        {
            vector<int> left = preorder1(root->left);
            vector<int> right = preorder1(root->right);
            result.push_back(root->val);
            result.insert(result.end(), left.begin(), left.end());
            result.insert(result.end(), right.begin(), right.end());
        }
        return result;
    }

    vector<int> preorder2(TreeNode *root) {
        // 栈实现先序遍历
        vector<int> result;
        if (root == NULL) return result;

        stack<TreeNode*> s;
        TreeNode *tmp;

        s.push(root);
        while ( !s.empty() ) {
            tmp = s.top();
            s.pop();
            result.push_back(tmp->val);
            if (tmp->right) s.push(tmp->right);
            if (tmp->left)  s.push(tmp->left);
        }
        return result;
    }

    vector<int> inorder1(TreeNode *root) {
        vector<int> result;
        if (root) {
            vector<int> left = inorder1(root->left);
            result.insert(result.end(), left.begin(), left.end());
            result.push_back(root->val);
            vector<int> right = inorder1(root->right);
            result.insert(result.end(), right.begin(), right.end());
        }
        return result;
    }

    vector<int> inorder2(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        while ( !s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else if (!s.empty()) {
                root = s.top();
                s.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }

     vector<int> postorder1(TreeNode *root) {
        vector<int> result;
        if (root) {
            vector<int> left = postorder1(root->left);
            vector<int> right = postorder1(root->right);

            result.insert(result.end(), left.begin(), left.end());
            result.insert(result.end(), right.begin(), right.end());
            result.push_back(root->val);
        }
        return result;
    }

    vector<int> postorder2(TreeNode *root) {
        vector<int> result;
        if (!root) return result;
        //将“左右根”转置，就是“根右左”，即先序遍历的转置
        TreeNode *tmp;
        stack<TreeNode*> s;
        s.push(root);
        while ( !s.empty() ) {
            tmp = s.top();
            s.pop();
            result.push_back(tmp->val);
            if (tmp->left)
                s.push(tmp->left);
            if (tmp->right)
                s.push(tmp->right);
        }
        reverse(result.begin(), result.end());
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

    Solution sol;

    vector<int> ans = sol.postorder1(root);
    cout << "Inorder : ";
    for (int i=0; i<ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}
