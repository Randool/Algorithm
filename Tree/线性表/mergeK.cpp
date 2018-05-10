//http://www.lintcode.com/en/problem/merge-k-sorted-lists/
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

struct cmp {
    bool operator () (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

bool camp (const ListNode *a, const ListNode *b) {
    return a->val < b->val;
}

class Solution {
private:
    ListNode *head, *pre, *tmp;
public:
    Solution() {
        head = pre = tmp = NULL;
    }

    ListNode *mergeKLists1(vector<ListNode *> &lists) //385 ms
    {
        priority_queue<ListNode*, vector<ListNode*>, cmp> Q;

        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                Q.push(lists[i]);

        while (!Q.empty()) {
            tmp = Q.top(), Q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) Q.push(tmp->next);
        }

        return head;
    }

    ListNode *mergeKLists2(vector<ListNode* > &lists) //267 ms
    {
        vector<ListNode*> nodes;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode *p = lists[i];
            while (p) {
                nodes.push_back(p);
                p = p->next;
            }
        }
        sort(nodes.begin(), nodes.end(), camp);

        for (int i = 0; i < nodes.size(); ++i) {
            if (!head) head = nodes[i];
            else  tmp->next = nodes[i];
            tmp = nodes[i];
        }

        return head;
    }
};

int main() {
    Solution sol;

    return 0;
}
