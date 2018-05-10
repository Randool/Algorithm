#include <queue>
#include <cstdio>
#include <cstring>
const int MAXN = 102;
using namespace std;

int m,n,k,x1,x2,y1,y2;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char map[MAXN][MAXN];
bool visit[MAXN][MAXN];
struct node {
	int x, y, turn;
};

void bfs(node s1, node s2) {
	queue<node> q;
	node start, end;
	int i, nextx, nexty;
	memset(visit,0,sizeof(visit));
	start.x = s1.x;
	start.y = s1.y;
	start.turn = -1;
	q.push(start);

	while(!q.empty())
	{
		start = q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			nextx = start.x + dir[i][0];
			nexty = start.y + dir[i][1];
			while(nextx>=1 && nextx<=m && nexty>=1 && nexty<=n &&map[nextx][nexty]=='.')
			{
				if(!visit[nextx][nexty])
				{
					visit[nextx][nexty]=1;
					end.x = nextx;
					end.y = nexty;
					end.turn = start.turn + 1;
					if(end.x==s2.x && end.y==s2.y && end.turn<=k)
					{
						printf("yes\n");
						return;
					}
					q.push(end);
				}
				nextx += dir[i][0];
				nexty += dir[i][1];
			}
		}
	}
	printf("no\n");
	return;
}

int main() {
	int t;
	node s1, s2;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&m,&n);
		for(int i=1; i<=m; i++) {
			getchar();
			for(int j=1; j<=n; j++)
				scanf("%c", &map[i][j]);
		}
		scanf("%d%d%d%d%d", &k, &s1.y, &s1.x, &s2.y, &s2.x);
		if(s1.x==s2.x && s1.y==s2.y)
			printf("yes\n");
		else
			bfs(s1,s2);
	}
	return 0;
}
