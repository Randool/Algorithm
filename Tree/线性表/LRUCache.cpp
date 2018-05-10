#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int key, value, vis;
    Node *next;
    Node(int k, int v) : key(k), value(v), vis(0) {
        next = NULL;
    }
};

class LRUCache {
private:
    int capacity, size;
    Node *head, *tail;

public:
    LRUCache(int cap) : size(0), capacity(cap), head(NULL), tail(NULL) {}

    void Show_line() {
        Node *temp = this->head;
        while (temp) {
            printf("key: %d, value: %d\n", temp->key, temp->value);
            temp = temp->next;
        }
    }

    int get(int key)
    {
        int found = -1;
        Node *cur = this->head, *pre = NULL;
        while (cur) {
            if (cur->key == key) {
                found = cur->value;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        if (found != -1 && cur != tail) {
            if (pre)
                pre->next = cur->next;
            else // 第一个就命中
                head = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
        }

        return found;
    }

    void set(int key, int value)
    {
        Node *cur = this->head, *pre = NULL;
        bool found = false;
        while (cur) {
            if (cur->key == key) {
                found = true;
                cur->value = value;
                break;
            }
            pre = cur;
            cur = cur->next;
        }

        if (found && cur != tail) { //命中缓存，移动至最后
            if (pre)
                pre->next = cur->next;
            else
                head = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
        }
        else if (!found) { //没有命中缓存，判断是否已经占满，并添加缓存
            if (capacity == size) {
                if (capacity == 1) {
                    head->key = key, head->value = value;
                }
                else {
                    head = head->next; //丢弃访问次数最少的
                    tail->next = new Node(key, value);
                    tail = tail->next;
                }
            }
            else {
                size += 1;
                if (!tail) {
                    head = new Node(key, value);
                    tail = head;
                }
                else {
                    tail->next = new Node(key, value);
                    tail = tail->next;
                }
            }
        }
    }
};

int main() {
    //freopen("in.txt", "r", stdin);
    int cap, d, key, value;
    string item;
    cout << "capacity:";
    cin >> cap;
    LRUCache cache(cap);
    while (cin >> item) {
        if (item == "get") {
            cin >> key;
            cout << cache.get(key) << endl;
        }
        else if (item == "set") {
            cin >> key >> value;
            cache.set(key, value);
        }
        else if (item == "show") {
            cache.Show_line();
        }
        else break;
    }
    return 0;
}
/*
1
set 2 1
get 2
set 3 2
get 2
get 3
.
*/
