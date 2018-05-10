#include <bits/stdc++.h>
using namespace std;

struct TreapNode {
    /**
     * same : 与该节点相同的数个数
     */
    int val, size, key, same;
    TreapNode *lc, *rc;
    TreapNode() {}
    TreapNode(int value, TreapNode* node) {
        val = value;
        key = rand();
        size = same = 1;
        lc = rc = node;
    }

    void update() {
        size = lc->size + rc->size + same;
    }

    static int rand() {
        static int seed = 233;
        return seed = (int) seed * 482711LL % 2147483647;
    }

};

inline void Zig(TreapNode* node) {
    TreapNode* tmp =
}

int main() {

    return 0;
}
