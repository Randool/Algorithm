#include <cstdio>
#include <iostream> 
const int MAXN = 21;
using namespace std;

char map[MAXN][MAXN];
int W, H;
int ans, x, y;
void dfs(int X, int Y) {
	int x=X, y=Y;
	if(map[x][y]=='#' ||map[x][y]=='!') return;
	if(x<1 || x>H || y<1 || y>W) return;
	map[x][y]='!';
	ans++;
	dfs(x,y-1);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x+1,y);
}

int main() {
	while(~scanf("%d%d",&W,&H)) {
		if(W==0 || H==0) break;
		for(int i=1; i<=H; i++)
			for(int j=1; j<=W; j++) {
				cin>>map[i][j];
				if(map[i][j]=='@') {
					x=i;
					y=j;
				}
			}
		ans=0;
		dfs(x,y);
		printf("%d\n",ans);
	}
	return 0;
}
