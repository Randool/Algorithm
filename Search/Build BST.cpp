#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution
{
private:
    vector<TreeNode*> makeTree(int start, int end)
    {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(NULL);
            return result;
        }

        // DFS
        for (int i=start; i<=end; ++i) {
            vector<TreeNode*> left = makeTree(start, i-1);
            vector<TreeNode*> right = makeTree(i+1, end);

            for (int j=0; j<left.size(); ++j)
            {
                for (int k=0; k<right.size(); ++k)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n)
    {
        return makeTree(1, n);
    }
};

int main()
{
    /*
    1         3     3       2    1
     \       /     /       / \    \
      3     2     1       1   3    2
     /     /       \                \
    2     1         2                3
    */
    Solution sol;
    sol.generateTrees(5);

    return 0;
}
