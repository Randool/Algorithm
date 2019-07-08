// https://www.luogu.org/problemnew/show/P1514
#include <bits/stdc++.h>
using namespace std;
#define MX 501
#define INF 0x3fffffff

int N, M;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int h[MX][MX];
int low[MX][MX], high[MX][MX];
bool vis[MX][MX];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > M || h[x][y] <= h[nx][ny])
            continue;
        if (!vis[nx][ny]) dfs(nx, ny);
        low[x][y] = min(low[x][y], low[nx][ny]);
        high[x][y] = max(high[x][y], high[nx][ny]);
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &h[i][j]);
            low[i][j] = INF;
            high[i][j] = -INF;
        }
    }
    for (int j = 1; j <= M; ++j) {
        low[N][j] = high[N][j] = j;
    }
    for (int j = 1; j <= M; ++j) {
        if (!vis[1][j])
            dfs(1, j);
    }
    int cnt = 0;
    for (int j = 1; j <= M; ++j) {
        if (!vis[N][j]) ++cnt;
    }
    if (cnt) {
        printf("0\n%d", cnt);
        return 0;
    }

    int left = 1;
    while (left <= M) {
        int maxr = -INF;
        for (int j = 1; j <= M; ++j) {
            if (low[1][j] <= left) {
                maxr = max(maxr, high[1][j]);
            }
        }
        ++cnt;
        left = maxr + 1;
    }
    printf("1\n%d", cnt);

    return 0;
}
