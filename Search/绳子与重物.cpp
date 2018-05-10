// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1307
#include <bits/stdc++.h>
using namespace std;
#define MX 50005
typedef long long LL;

int ci, wi, pi;
struct Node { LL c, w, p; } node[MX];

bool update(int p, int w) {
    while (p != -1) {
        node[p].w += w;
        if (node[p].w > node[p].c) return 1;
        p = node[p].p;
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &ci, &wi, &pi);
        node[i].c = ci, node[i].w = wi, node[i].p = pi;
        if (wi > ci || update(pi, wi)) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", N);
    return 0;
}
