#include <cstdio>
#include <cstring>
#include <iostream>
const int MAXN = 201;
using namespace std;
int a[MAXN][MAXN], dp[MAXN<<1][MAXN][MAXN];

int main() {
	int m, n, step, x1, x2, i, j;
	while(~scanf("%d%d",&m,&n)) {
		for(i=1; i<=m; i++)
			for(j=1; j<=n; j++)
				scanf("%d",&a[i][j]);
		memset(dp,0,sizeof(dp));
		dp[0][1][1]=a[1][1];
		for(step=1; step<=m+n-1; step++) {
			for(x1=1; x1<=step && x1<=m; x1++)
				for(x2=1; x2<=step && x2<=m; x2++) {
					if(x1>=2 && x2>=2)
						dp[step][x1][x2] = max(dp[step][x1][x2], dp[step-1][x1-1][x2-1]+a[x1][step+1-x1]+(x1==x2?0:a[x2][step+1-x2]));
					if(x1>=2 && step-x2>=1)
						dp[step][x1][x2] = max(dp[step][x1][x2], dp[step-1][x1-1][x2]+a[x1][step+1-x1]+(x1==x2?0:a[x2][step+1-x2]));
					if(x2>=2 && step-x1>=1)
						dp[step][x1][x2] = max(dp[step][x1][x2], dp[step-1][x1][x2-1]+a[x1][step+1-x1]+(x1==x2?0:a[x2][step+1-x2]));
					if(step-x1>=0 && step-x2>=0)
						dp[step][x1][x2] = max(dp[step][x1][x2], dp[step-1][x1][x2]+a[x1][step+1-x1]+(x1==x2?0:a[x2][step+1-x2]));
				}
		}
		printf("%d\n",dp[m+n-1][m][m]);
	}
	return 0;
}
/*dp[step][x1][x2] =
					max(dp[step-1][x1][x2], dp[step-1][x1][x2-1],
						dp[step-1][x1-1][x2], dp[step-1][x1-1][x2-1])
					+ a[x1][step+1-x1] + (x1==x2 ? 0 : a[x2][step+1-x2]);*/
//printf("dp[%d][%d][%d]=%d ",step,x1,x2,dp[step][x1][x2]);
/*
3 3
1 3 3
2 1 3
2 2 1

17

5 5
1 10 10 10 10
10 1 1 1 1
10 1 1 1 1
10 1 1 1 1
10 10 10 10 1

115

10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 11
1 1 1 1 2 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 2 1 1 1 1 1 1 1
1 1 1 1 5 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 2 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

52
*/
