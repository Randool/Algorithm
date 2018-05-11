#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

#define MAXN 505

int num, max_d, d, t, cur, cnt;

struct Node {
    int fa, dist, isRoot;
    Node(int father=0, int distance=0) {
        fa = father, dist = distance;
        isRoot = 0;
    }
} root, nodes[MAXN];

queue<int> leaves;

int solution() {
    int ans = 0, cur, fa;

    while (!leaves.empty()) {
        cur = leaves.front();
        leaves.pop();
        if (nodes[cur].isRoot) continue;

        int acc_dist = 0;

        while (true) {
            fa = nodes[cur].fa;
            acc_dist += nodes[cur].dist;
            if (acc_dist > max_d) {
                ans += 1;
                nodes[cur].isRoot = 1;
                if (!nodes[fa].isRoot) leaves.push(fa);
                break;
            }
            if (nodes[fa].isRoot) break;
            cur = fa;
        }
    }

    return ans;
}

int main() {
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt","w");

    fscanf(fi, "%d", &num);
    for (int i = 1; i <= num; ++i) {
        fscanf(fi, "%d", &t);
        if (!t) leaves.push(i);

        while (t--) {
            fscanf(fi, "%d %d", &cur, &d);
            nodes[cur].fa = i;
            nodes[cur].dist = d;
        }
    }
    fscanf(fi, "%d", &max_d);

    nodes[1].isRoot = 1;
    cnt = solution();

    if (cnt == num-1) printf("No Solution!\n");
    else printf("%d\n", cnt);

    return 0;
}
