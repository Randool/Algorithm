
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
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
private:
    vector<int> layer;
    TreeNode* cur = NULL;
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;

        int dir = 0, lay = 0;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            stack<TreeNode*> tmp;
            result.push_back(layer);
            int size = s.size();
            for (int i=0; i<size; ++i) {
                cur = s.top(), s.pop();
                result[lay].push_back(cur->val);
                if (!dir) {
                    if (cur->left) tmp.push(cur->left);
                    if (cur->right) tmp.push(cur->right);
                }
                else {
                    if (cur->right) tmp.push(cur->right);
                    if (cur->left) tmp.push(cur->left);
                }
            }
            ++lay;
            dir = (dir+1) % 2;
            s = tmp;
        }
        return result;
    }
};

int main() {
    /**
      *   3
      *  9  20
      *    15  7
      *  21 25
      */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(21);
    root->right->left->right = new TreeNode(25);


    Solution sol;
    vector<vector<int> > result;
    result = sol.zigzagLevelOrder(root);
    for (int i=0; i<result.size(); ++i) {
        for (int j=0; j<result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
