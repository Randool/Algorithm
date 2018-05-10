#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1002
#define INF 0x3f3f3f3f
using namespace std;

int map[MAXN][MAXN];
bool vis[MAXN];
int N,M,S,E,W;

void Init(int n) {
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			map[i][j] = INF;
}

int Prim() {
	int cost = 0;
	for(int t=1; t<N; t++) //一共需要找 N-1次
	{
		int min = INF, newNodeX, newNodeY, newCost;
		//一个节点在子数中，另一个不在子数中
		for(int i=1; i<=N; i++)
			if(vis[i] == 1)
				for(int j=1; j<=N; j++)
					if(vis[j] == 0)
						if( map[i][j] < min )
						{
							newNodeX = i;
							newNodeY = j;
							newCost = map[i][j];
							min = newCost;
						}

		cost += map[newNodeX][newNodeY];
		vis[newNodeY] = 1;
		map[newNodeX][newNodeY] = map[newNodeY][newNodeX] = INF;
	}
	return cost;
}

int main() {
	while(~scanf("%d%d", &N, &M)) {
		Init(N);
		memset(vis,0,sizeof(vis));
		vis[1] = 1;
		for(int i=1; i<=M; i++) {
			scanf("%d%d%d", &S, &E, &W);
			map[S][E] = map[E][S] = W;
		}
		printf("%d\n",Prim());
	}
	return 0;
}
/*
5 6
3 4 1
1 2 3
2 4 5
1 5 7
3 5 8
1 3 10

9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 9 7
2 8 11
3 9 2
7 9 6
3 6 4
4 6 14
1 8 8
*/
