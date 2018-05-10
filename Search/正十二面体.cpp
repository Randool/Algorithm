#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[25];
int Case = 0;
int cnt, ans[25], map[25][5];

void dfs(int m, int len, int c) {
	vis[m] = 1;
	ans[len] = m;
	for(int i=0; i<3; i++) {
		int t = map[m][i];

		if(t==c && len==19) { //ÖÐÖ¹Ìõ¼þ 
			printf("%d:  ", ++Case);
			for(int j=0; j<20; j++)
				printf("%d ", ans[j]);
			printf("%d\n", c);
		}

		if(!vis[t])
			dfs(t, len+1, c);
	}
	vis[m] = 0;
}

int main() {
	int m;
	for(int i=1; i<=20; i++)
		scanf("%d%d%d",&map[i][0], &map[i][1], &map[i][2]);
	while(~scanf("%d",&m)) {
		if(!m) break;
		memset(vis,0,sizeof(vis));
		dfs(m,0,m);
	}
	return 0;
}

