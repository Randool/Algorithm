// https://www.luogu.org/problemnew/solution/P3379
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500001

int deepth[MAXN];
int fa[MAXN][20];
int lg[MAXN];

int head[MAXN];
struct node {
    int to, next;
} e[MAXN << 1];
int total;
void add_edge(int x, int y) {
    e[++total].to = y;
    e[total].next = head[x];
    head[x] = total;
}

void dfs(int cur, int father) {
    deepth[cur] = deepth[father] + 1;
    fa[cur][0]=  father;
    for (int i = 1; (1<<i) <= deepth[cur]; ++i)
        fa[cur][i] = fa[ fa[cur][i-1] ][i-1];
    // ��ǰ��
    for (int i = head[cur]; i; i = e[i].next)
        if (e[i].to != father)
            dfs(e[i].to, cur);
}

int LCA(int x, int y) {
    if (deepth[x] < deepth[y])
        swap(x, y);
    while (deepth[x] > deepth[y])
        x = fa[x][ lg[deepth[x]-deepth[y]]-1 ];
    if (x == y)
        return x;
    for (int i = lg[deepth[x]]; i >= 0; --i)
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    return fa[x][0];
}

int main() {
    int n, m, s, x, y;
    scanf("%d%d%d", &n,&m,&s);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d%d", &x,&y);
        add_edge(x, y);
        add_edge(y, x);
    }
    dfs(s, 0);

    for (int i = 1; i <= n; ++i)
        lg[i] = lg[i-1] + (1<<lg[i-1]==i);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x,&y);
        printf("%d\n", LCA(x, y));
    }
    return 0;
}
