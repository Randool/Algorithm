#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int a, b, c;
int map[MAXN][MAXN];

void Floyd() {
	for (int k=1; k<=N; k++)
		for (int i=1; i<=N; i++)
			for (int j=1; j<=N; j++)
			{
				if (map[i][k] == INF || map[k][j] == INF)
					continue;
				map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
			}
}

int main()
{
    //freopen("in.txt","r", stdin);
    while(scanf("%d%d", &N, &M) && N+M)
    {
    	for (int i=0; i<MAXN; i++)
    		for (int j=0; j<MAXN; j++)
    			map[i][j] = (i==j) ? 0 : INF;
        for (int i=0; i<M; i++) {
        	scanf("%d%d%d", &a, &b, &c);
        	map[a][b] = map[b][a] = c;
		}
        Floyd();
        printf("%d\n", map[1][N]);
    }

    return 0;
}
