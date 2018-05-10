#include <cstdio>
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

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n:    An integer
     * @return:     Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
            ++len, temp = temp->next;
        len -= n;
        temp = head;
        while (len--)
            temp = temp->next;

        return temp;
    }
};

ListNode *make_head() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
}

int main () {
    Solution sol;
    printf("%d\n", sol.nthToLast(make_head(), 1)->val);
    return 0;
}
