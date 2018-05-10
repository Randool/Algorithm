#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define INF 0x7fffff
typedef long long LL;

struct Edge{
    int capacity;
    int flow;
} edge[MAXN][MAXN]; // 邻接矩阵

int n, m;
int flag[MAXN], prev[MAXN], alpha[MAXN];

void Init() {
    memset(flag, -1, sizeof(flag));
    memset(prev, -1, sizeof(prev));
    memset(alpha, -1, sizeof(alpha));
    alpha[0] = INF;
    flag[0] = prev[0] = 0;
}

void Ford() {
    queue<int> Q;
    while (true) // 标号直到不可改进
    {
        Init();
        Q.push(0);
        while (!Q.empty() && flag[n-1] == -1)
        {
            int u = Q.front();
            Q.pop();
            for (int i = 0; i < n; ++i)
            {
                if (flag[i] == -1) // 如果未标记
                {
                     // 正向且未满
                    if (edge[u][i].capacity < INF && edge[u][i].flow < edge[u][i].capacity)
                    {
                        flag[i] = 0;
                        prev[i] = u;
                        alpha[i] = min(alpha[i], edge[u][i].capacity - edge[u][i].flow);
                        Q.push(i);
                    }
                    // 反向且有流量
                    else if (edge[u][i].capacity < INF && edge[u][i].flow > 0)
                    {
                        flag[i] = 0;
                        prev[i] = -u;
                        alpha[i] = min(alpha[i], edge[i][u].flow);
                        Q.push(i);
                    }
                }
            } // out of for

            flag[u] = 1; // u已检查

        } // end of while(!Q.empty() && flag[n-1]] == -1)


        // 当汇入点没有得到标记，退出while(true)
        if (flag[n-1] == -1 || alpha[n-1] == 0) break;

        // 更新流量
        int k1 = n-1, k2 = abs(prev[k1]);
        int a = alpha[n-1]; // 可改量
        while (1) {
            if (edge[k2][k1].flow < INF) // 正向
                edge[k2][k1].flow += a;
            else edge[k1][k2].flow -= a;
            if (k2 == 0) break;
            k1 = k2;
            k2 = abs(prev[k2]);
        } // end of while(true)

        int maxFlow = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && edge[i][j].flow < INF) // 出流
                    maxFlow += edge[i][j].flow;
                if (edge[i][j].flow < INF)
                    printf("%d-->%d : %d\n", i, j, edge[i][j].flow);
            }
        }
        printf("maxFlow : %d\n", maxFlow);

    } // end of while(true)
}

int main() {
    freopen("in.txt", "r", stdin);
    int u, v, c, f;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            edge[i][j].capacity = edge[i][j].flow = INF;

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &u, &v, &c, &f);
        edge[u][v].capacity = c;
        edge[u][v].flow = f;
    }

    Ford();

    return 0;
}
