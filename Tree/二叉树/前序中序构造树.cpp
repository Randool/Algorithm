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

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
private:
    typedef vector<int>::iterator Iter;
    TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend)
    {
        if (istart == iend)
            return NULL;
        int rootval = *pstart;
        TreeNode *result = new TreeNode(rootval);
        Iter iterroot = find(istart, iend, rootval);

        result->left = buildTreeRecur(istart, iterroot, pstart+1, pstart+1+(iterroot-istart));
        result->right = buildTreeRecur(iterroot+1, iend, pstart+1+(iterroot-istart), pend);

        return result;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeRecur(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
    }
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
};

int main()
{
    /**
      *   3
      *  9  20
      *    15  7
      *  21 25
      */
    int io[] = {9,3,21,15,25,20,7};
    int po[] = {3,9,20,15,21,25,7};
    vector<int> preorder(po,po+7);
    vector<int> inorder(io, io+7);
    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    cout << "preorder: ";
    vector<int> pre = sol.preorder1(root);
    for (int i=0; i<pre.size(); ++i) cout << pre[i] << " ";
    cout << endl << "inorder: ";

    vector<int> ino = sol.inorder1(root);
    for (int i=0; i<ino.size(); ++i) cout << ino[i] << " ";

    return 0;
}
