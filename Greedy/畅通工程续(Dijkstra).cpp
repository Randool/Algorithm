//http://acm.hdu.edu.cn/showproblem.php pid=1874
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 205
#define INF 0x3f3f3f3f
using namespace std;

int N, M, a, b, c, start, End;
int map[MAX][MAX], d[MAX];
bool v[MAX];

void Dijkstra(int s, int e)
{
	memset(v, 0, sizeof(v));
	for(int i=0; i<N; i++) d[i] = i==s   0 : INF;
	
	for(int i=0; i<N; i++)
	{
		int x, m = INF;
		for(int y=0; y<N; y++)
			if(!v[y] && d[y]<m)
				m = d[x=y];
		v[x] = 1;
		for(int y=0; y<N; y++)
			d[y] = min(d[y], d[x]+map[x][y]);
	}
	if(d[e] != INF)
		printf("%d\n", d[e]);
	else
		printf(" \n");
}

int main() 
{
	while(~scanf("%d%d", &N, &M) , N+M )
	{
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				map[i][j] = map[i][j] = i==j   0 : INF;
				
		for(int i=0; i<M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}
		
		scanf("%d%d", &start, &End);
		Dijkstra(start, End);
	}
	return 0;
}
