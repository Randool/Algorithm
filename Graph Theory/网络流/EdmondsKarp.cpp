//https://www.luogu.org/problemnew/show/P3376
#include <bits/stdc++.h>
#define MX 100001
#define NX 10001
#define INF 0x3fffffff
using namespace std;

int N, M, S, T, u, v, w;
int g[NX][NX];  // 邻接矩阵
int pre[NX];    // 每个点的前驱
int flow[NX];   // 源到该点的流量

int bfs(int s, int t) {
    queue<int> Q;
    memset(pre, -1, sizeof(pre));
    pre[s] = 0;
    Q.push(s);
    flow[s] = INF;
    while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        if (p == t) break;
        for (int i = 0; i <= N; ++i) {
            if (g[p][i] > 0 && pre[i] == -1) {
                pre[i] = p;
                flow[i] = min(flow[p], g[p][i]);
                Q.push(i);
            }
        }
    }
    if (pre[t] == -1) return -1;
    return flow[t];
}

int EdmondsKarp(int s, int t) {
    int increase = 0, maxflow = 0;
    while ((increase = bfs(s, t)) != -1) {
        int k = t;
        while (k != s) {
            int last = pre[k];
            g[last][k] -= increase;
            g[k][last] += increase;
            k = last;
        }
        maxflow += increase;
    }
    return maxflow;
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &N, &M, &S, &T);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] += w;
    }
    printf("%d\n", EdmondsKarp(S, T));
    return 0;
}
