#include <bits/stdc++.h>
using namespace std;

class TreeNode {    //Definition of TreeNode:
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class DoublyListNode {  //Definition of Doubly-ListNode
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

class Solution {
private:
    DoublyListNode *head, *cur, *tmp;

    void makeList(TreeNode *root) {
        if (root->left) makeList(root->left);

        tmp = new DoublyListNode(root->val);
        if (!head)
            head = tmp;
        else {
            cur->next = tmp;
            tmp->prev = cur;
        }
        cur = tmp;

        if (root->right) makeList(root->right);
    }

public:
    Solution() : head(NULL), cur(NULL), tmp(NULL) {}

    DoublyListNode *bstToDoublyList(TreeNode *root) {
        if (!root) return head;
        makeList(root);
        return head;
    }

};

int main() {


    return 0;
}
