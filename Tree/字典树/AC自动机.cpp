#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum;
    Node *next[26];
    Node *fail;  /// 失配指针
    Node() {
        sum = 0;
        fail = NULL;
        memset(next, 0, sizeof(next));
    }
};

/// 建立字典树
void insert(char *s, Node *root) {
    Node *p = root;
    for (int i = 0; s[i]; ++i) {
        int t = s[i] - 'a';
        if (root->next[t] == NULL)
            p->next[t] = new Node;
        p = p->next[t];
    }
    p->sum += 1;
}

/// 失配指针
void build_fail_pointer(Node *root) {
    queue<Node *> Q;
    Q.push(root);
    Node *p = NULL, *temp = NULL;
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        for (int i = 0; i < 26; ++i) {
            if (temp->next[i] == NULL) continue;
            if (temp == root) (temp->next[i])->fail = root;
            else {  /// 寻找最长前缀
                p = temp->fail;
                while (p) {
                    if (p->next[i]) {
                        (temp->next[i])->fail = p->next[i];
                        break;
                    }
                    p = p->fail;
                }
            }
            Q.push(temp->next[i]);
        }
    }
}

/// ac自动机
void ac_automation(char *ch, Node *root) {
    Node *p = root;
    int len = strlen(ch);
    for (int i = 0; i < len; ++i)
    {
        int x = ch[i] - 'a';

        while (p->next[x] == NULL && p != root)
            p = p->fail;

        p = p->next[x];
        if (!p) p = root;

        Node *temp = p;
        while (temp != root)
        {
            if (temp->sum >= 0)
            {
                cnt += temp->sum;
                temp->sum = -1;
            }
            else break;
            temp = temp->fail;
        }

    }
}

int main()
{


    return 0;
}
