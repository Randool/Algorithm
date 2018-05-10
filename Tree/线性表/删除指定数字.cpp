#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * removeElements(ListNode *head, int val) {
        ListNode appd(0);
        appd.next = head;
        head = &appd;

        while (head->next != NULL) {
            if (head->next->val == val)
                head->next = head->next->next;
            else head = head->next;
        }

        return appd.next;
    }
};

void show_line(ListNode* head) {
    ListNode *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    return;
}

int main()
{
    Solution sol;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next->next = new ListNode(3);

    head = sol.removeElements(head, 3);
    show_line(head);

    return 0;
}
