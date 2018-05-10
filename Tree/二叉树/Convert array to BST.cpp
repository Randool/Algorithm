#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

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
    TreeNode* cur = NULL;
public:
    TreeNode *sortedArrayToBST(vector<int> &A)
    {
        TreeNode* root = NULL;
        if (A.size() == 0)
            return root;

        int mid_pos = (A.size() + 1) >> 1;
        vector<int>::iterator mid = A.begin() + mid_pos - 1;
        int mid_val = *mid;

        root = new TreeNode(mid_val);
        vector<int> left, right;
        left.insert(left.begin(), A.begin(), mid);
        right.insert(right.begin(), mid+1, A.end());

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL) return cur;
        vector<int> A;
        while (head) {
            A.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(A);
    }
};

int main()
{
    /*
         4
       /   \
      2     6
     / \    / \
    1   3  5   7
    */
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution sol;
    TreeNode* root = sol.sortedListToBST(head);

    return 0;
}
