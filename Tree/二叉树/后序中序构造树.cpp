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
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
private:
    typedef vector<int>::iterator Iter;
    TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend)
    {
        if (istart == iend)
            return NULL;

        int rootval = *pstart;
        TreeNode* root = new TreeNode(rootval);
        Iter iterroot = find(istart, iend, rootval);

        //po[] = {3,20,7,15,25,21,9};
        //io[] = {9,3,21,15,25,20,7};
        root->left = buildTreeRecur(istart, iterroot, pstart+(iend-iterroot), pend);
        root->right = buildTreeRecur(iterroot+1, iend, pstart+1, pstart+1+(iterroot-istart));

        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        reverse(postorder.begin(), postorder.end());
        return buildTreeRecur(inorder.begin(), inorder.end(),postorder.begin(), postorder.end());
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
    int po[] = {9,21,25,15,7,20,3};
    int io[] = {9,3,21,15,25,20,7};
    vector<int> pstorder(po,po+7);
    vector<int> inorder(io, io+7);
    Solution sol;
    TreeNode *root = sol.buildTree(inorder, pstorder);

    cout << "Postorder: ";
    vector<int> post_ans = sol.postorder1(root);
    for (int i=0; i<post_ans.size(); ++i) cout << post_ans[i] << " ";
    cout << endl << "Inorder: ";

    vector<int> inorder_ans = sol.inorder1(root);
    for (int i=0; i<inorder_ans.size(); ++i) cout << inorder[i] << " ";


    return 0;
}
