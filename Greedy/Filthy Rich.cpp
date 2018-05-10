#include <cstdio>
#include <cstring>
#define MAXN 1001
using namespace std;

int map[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
	int t, cnt=0;
	scanf("%d",&t);
	while(t--) {
		int m,n;
		scanf("%d%d",&m, &n);
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				scanf("%d", &map[i][j]);
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				dp[i][j] = map[i-1][j-1] +
				           ( dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j] );
		printf("Scenario #%d:\n",++cnt);
		printf("%d\n\n",dp[m][n]);
	}
	return 0;
}
/*
1
3 4
1 10 8 8
0 0 1 8
0 27 0 4
*/

//http://acm.hdu.edu.cn/diy/contest_showproblem.php?pid=1013&cid=31281
