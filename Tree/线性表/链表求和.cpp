#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *make_chain(int n) {
    int t;
    ListNode *head = NULL, *p = NULL;
    while (n--) {
        cin >> t;
        ListNode *tmp = new ListNode(t);
        if (!head) head = tmp;
        else    p->next = tmp;
        p = tmp;
    }

    return head;
}

void show_line(ListNode* head) {
    ListNode *p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        else cout << "->null" << endl;
        p = p->next;
    }
    return;
}

class Solution {
private:
    ListNode *reverse(ListNode *head) {
        ListNode *p = head;
        stack<int> S;
        while (p) {
            S.push(p->val);
            p = p->next;
        }
        ListNode *result = NULL, *cur = NULL;
        while (!S.empty()) {
            ListNode *tmp = new ListNode(S.top());
            S.pop();
            if (!result) result = tmp;
            else cur->next = tmp;
            cur = tmp;
        }
        return result;
    }
public:
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode *result = NULL, *p = NULL;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 || p2) {
            int added = (p1==NULL ? 0 : p1->val) + (p2==NULL ? 0 : p2->val);
            ListNode *tmp = new ListNode(added);
            if (!result)
                result = tmp;
            else
                p->next = tmp;
            p = tmp;

            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
        }
        p = result;
        while (p) {
            if (p->val >= 10) {
                p->val -= 10;
                if (p->next)
                    p->next->val += 1;
                else
                    p->next = new ListNode(1);
            }
            p = p->next;
        }
        return result;
    }

    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        ListNode *head1 = reverse(l1), *head2 = reverse(l2);
        ListNode *p1 = head1, *p2 = head2;
        ListNode *result = NULL, *cur = NULL;

        while (p1 || p2) {
            ListNode *tmp = NULL;
            if (p1 && p2) {
                tmp = new ListNode(p1->val + p2->val);
                p1 = p1->next, p2 = p2->next;
            }
            else if (p1) {
                tmp = new ListNode(p1->val);
                p1 = p1->next;
            }
            else {
                tmp = new ListNode(p2->val);
                p2 = p2->next;
            }
            if (!result) result = tmp;
            else cur->next = tmp;
            cur = tmp;
        }

        cur = result;
        while (cur) {
            if (cur->val >= 10) {
                cur->val -= 10;
                if (cur->next) cur->next->val += 1;
                else cur->next = new ListNode(1);
            }
            cur = cur->next;
        }

        return reverse(result);
    }
};


int main() {
    freopen("in.txt", "r", stdin);
    int n1, n2;
    cin >> n1 >> n2;
    ListNode *l1 = make_chain(n1);
    ListNode *l2 = make_chain(n2);

    Solution sol;
    ListNode *result = sol.addLists2(l1, l2);

    show_line(result);

    return 0;
}
