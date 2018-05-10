// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1444
#include <bits/stdc++.h>
using namespace std;
#define MAXN 3005
#define INF 0x3f3f3f3f

int n, m, a, b;
int s1, t1, l1, s2, t2, l2, cnt;
int dist[MAXN][MAXN];
bool inq[MAXN];
vector<int> G[MAXN];

void SPFA(int s) {
    int u;
    memset(inq, 0, sizeof(inq));
    for (int i = 1; i <= n; ++i)
        if (i == s) dist[i][i] = 0;
        else dist[s][i] = INF;
    queue<int> Q;
    Q.push(s);
    inq[s] = 1;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop(), inq[u] = 0;
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i];
            if (dist[s][v] > dist[s][u] + 1)
            {
                dist[s][v] = dist[s][u] + 1;
                if (!inq[v])
                    Q.push(v), inq[v] = 1;
            }
        }
    }
    return ;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    scanf("%d%d%d", &s1, &t1, &l1);
    scanf("%d%d%d", &s2, &t2, &l2);

    for (int i = 1; i <= n; ++i) SPFA(i);

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j)
            if (dist[i][j] != dist[j][i]) cout << dist[i][j] << " " << dist[j][i] << endl;
    }

    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) puts("-1");
    else {
        cnt = dist[s1][t1] + dist[s2][t2];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                // s 和 t 连边 ij 有两种情况 ：sijt & sjit
                if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1 && dist[s2][i] + dist[i][j] + dist[j][t2] <= l2)
                    cnt = min(dist[s1][i] + dist[i][j] + dist[j][t1] + dist[s2][i] + dist[j][t2], cnt);

                if (dist[t1][i] + dist[i][j] + dist[j][s1] <= l1 && dist[s2][i] + dist[i][j] + dist[j][t2] <= l2)
                    cnt = min(dist[t1][i] + dist[i][j] + dist[j][s1] + dist[s2][i] + dist[j][t2], cnt);

                if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1 && dist[t2][i] + dist[i][j] + dist[j][s2] <= l2)
                    cnt = min(dist[s1][i] + dist[i][j] + dist[j][t1] + dist[t2][i] + dist[j][s2], cnt);

                if (dist[t1][i] + dist[i][j] + dist[j][s1] <= l1 && dist[t2][i] + dist[i][j] + dist[j][s2] <= l2)
                    cnt = min(dist[t1][i] + dist[i][j] + dist[j][s1] + dist[t2][i] + dist[j][s2], cnt);
            }
        printf("%d\n", m - cnt);
    }
    return 0;
}
/*
10 11
1 3
2 3
3 4
4 5
4 6
3 7
3 8
4 9
4 10
7 9
8 10
1 5 3
6 2 3
*/
