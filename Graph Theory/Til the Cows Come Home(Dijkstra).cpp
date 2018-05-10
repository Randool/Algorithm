#include <cstdio>
#include <iostream>
#define MAXN 2005
#define INF 0x3f3f3f3f
using namespace std;

int t, n; //(2 <= N <= 1000) (1 <= T <= 2000)
int edge[MAXN][MAXN];
int dis[MAXN];
int book[MAXN];
int u, v;

void Init() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if(i==j)
                edge[i][j] = 0;
            else
                edge[i][j] = INF;
        }
    }
}

void Input() {
    int x, y, v;
    for (int i=0; i<t; i++) {
        scanf("%d%d%d", &x, &y, &v);
        if (v < edge[x][y])
            edge[x][y] = edge[y][x] = v;
    }
}

void dijkstra()
{
    for (int i=1; i<=n; i++)
    {
        book[i] = 0;
        dis[i] = edge[n][i];
    }

    int _min, tmp;

    for (int i=1; i<=n; i++)
    {
        _min = INF;
        for (int j=1; j<=n; j++)
        {
            if (!book[j] && dis[j] < _min)
            {
                _min = dis[j];
                tmp = j;
            }
        }

        book[tmp] = 1;

        for (int j=1; j<=n; j++) {
            if (!book[j])
                dis[j] = min(dis[j], dis[tmp] + edge[tmp][j]);
        }
    }
}

int main() {
	//freopen("in.txt", "r", stdin);

    scanf("%d%d", &t, &n);
    Init();
    Input();
    dijkstra();

    printf("%d\n", dis[1]);

	return 0;
}
