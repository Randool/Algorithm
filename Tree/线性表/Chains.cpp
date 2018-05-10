#include <cstdio>
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

void delete_chain(ListNode *head) {
    ListNode *p = head;
    while (head) {
        p = head->next;
        delete head;
        head = p;
    }
    return;
}

void show_line(ListNode *head) {
    ListNode *p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        else cout << "->null" << endl;
        p = p->next;
    }
    return;
}


int main() {

    return 0;
}
