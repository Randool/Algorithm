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
public:
    /*http://www.lintcode.com/zh-cn/problem/intersection-of-two-linked-lists/*/
    // 判断两个链表是否有交集，时间复杂度O(n)，空间复杂度O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = (a ? a->next : headB);
            b = (b ? b->next : headA);
        }
        return a;
    }

    /*http://www.lintcode.com/zh-cn/problem/linked-list-cycle/*/
    // 不使用额外空间判环（快慢指针的应用）
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    /*http://www.lintcode.com/zh-cn/problem/linked-list-cycle-ii/*/
    // 不使用额外空间返回环入口
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *chaser = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        while (slow && chaser) {
            slow = slow->next;
            chaser = chaser->next;
            if (slow == chaser) return chaser;
        }
        return NULL;
    }
    /*http://www.cnblogs.com/snake-hand/p/3148328.html*/
};

int main() {
    freopen("in.txt", "r", stdin);
    Solution sol;
    int n1, n2;
    cin >> n1;
    ListNode *l1 = make_chain(n1);
    show_line(l1);

    if (sol.hasCycle(l1))
        puts("1");
    else puts("0");

    return 0;
}
