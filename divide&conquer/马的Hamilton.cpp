#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define MAXN 101
using namespace std;

int n, m;
int G[MAXN][MAXN];
struct Node {
    int x, y;
} Q[MAXN*MAXN];

int go_x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int go_y[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void print(int n, int m) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            printf("(%d,%d) ", Q[i*n+j].x, Q[i*n+j].y);
        printf("\n");
    }
    printf("\n");
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            printf("%4d", G[i][j]);
        printf("\n");
    }
}

bool judge(int x, int y) {
    for (int i=0; i<8; i++)
        if (x+go_x[i]==1 && y+go_y[i]==1)
            return 1;
    return 0;
}

void DFS(int cur_x, int cur_y, int step) {
    if (step == n*m+1 && judge(cur_x, cur_y)) {
        print(n, m);
        exit(1);
    }
    int next_x, next_y;
    for (int i=0; i<8; i++)
    {
        next_x = cur_x + go_x[i];
        next_y = cur_y + go_y[i];
        if (G[next_x][next_y] || next_x == 0 || next_x > n || next_y == 0 || next_y > m)
            continue;
        Q[step].x = next_x;
        Q[step].y = next_y;
        G[next_x][next_y] = step;
        DFS(next_x, next_y, step+1);
        G[next_x][next_y] = 0;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(G,0,sizeof(G));
    Q[1].x = Q[1].y = 1;
    G[1][1] = 1;
    DFS(1,1,2);

    return 0;
}
