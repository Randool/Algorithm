#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 30

int n, m, a, b;
vector<int> G[MAXN];
int select[MAXN];
bool cant_draw[MAXN][MAXN];

void Init() {
    memset(select, 0, sizeof(select));
    memset(cant_draw, 0, sizeof(cant_draw));
}

int BFS(int start) {
    Init();
    queue<int> q; q.push(start);
    int cur, next;
    while (!q.empty()) {
        cur = q.front(); q.pop();
        for (int i = 1; i <= n; ++i) {
            if (!cant_draw[cur][i]) {
                select[cur] = i;
                break;
            }
        }
        for (int i = 0; i < G[cur].size(); ++i) {
            next = G[cur][i];
            if (select[next]) continue;
            cant_draw[next][select[cur]] = 1;
            q.push(next);
        }
    }
    int biggest = 0;
    for (int i = 1; i <= n; ++i)
        biggest = max(biggest, select[i]);
    // printf("%d ", biggest);
    return biggest;
}
/*
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/

int main() {
    /// draw colors
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int biggest = n;
    for (int i = 1; i <= n; ++i)
        biggest = min(BFS(i), biggest);

    printf("%d", biggest);

    return 0;
}
