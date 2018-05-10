//http://acm.hdu.edu.cn/showproblem.php?pid=3790 
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 1005

struct Node{
	int dis;
	int cost;
} map[MAX][MAX];

int N, M, a, b, c, d, start, End;
int dis[MAX], cost[MAX];
bool vis[MAX];

void Dijkstra(int s, int e) {
	int i, j, min, pos;
	memset(vis,0,sizeof(vis));
	dis[s] = cost[s] = 0;
	vis[s] = 1;
	for(int i=0; i<=N; i++)
	{
		cost[i] = map[s][i].cost;
		dis[i] = map[s][i].dis;
	}
	
	for(int i=1; i<N; i++)
	{
		min = INF;
		for(int j=0; j<n; j++)
		{
			if(!vis[j] && cost[j] < min)
			{
				
				
			}
		}
	}
	printf("\n",);
}

int main()
{
	while(~scanf("%d%d", &N, &M) , N+M )
	{
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				map[i][j].cost = map[i][j].dis = i==j ? 0 : INF;
				
		for(int i=1; i<=M; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			map[a][b].dis = map[b][a].dis = c;
			map[a][b].cost = map[b][a].cost = d;
		}
		
		scanf("%d%d", &start, &End);
		
		Dijkstra(start, End);
	}
	return 0;
}
