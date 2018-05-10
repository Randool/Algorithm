// https://vjudge.net/problem/HYSBZ-3229
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAXN 40005
#define INF 0x3f3f3f3f
using namespace std;

int n;
int a[MAXN];
int sum[MAXN];

void n2_DP(int n, int** s, int** dp) {
	int i, j, k, len, tmp, end;

	for (i=1; i<=n; ++i)
		dp[i][i] = 0, s[i][i] = i;

	// 平行四边形优化
	for (len = 2; len <= n; ++len) {
		for (i = 1; i <= n-len+1; ++i) {
			int end = i+len-1;
			tmp = INF;
			k = 0;
			for (j = s[i][end-1]; j <= s[i+1][end]; ++j)
			{
				if (tmp > dp[i][j] + dp[j+1][end] + sum[end]-sum[i-1]) {
					tmp = dp[i][j] + dp[j+1][end] + sum[end]-sum[i-1];
					k = j;
				}
			}
			dp[i][end] = tmp;
			s[i][end] = k;
		}
	}
	printf("%d\n", dp[1][n]);
}

int main() {
	while(~scanf("%d", &n)) {
		int** s = (int**)malloc((n+5)*sizeof(int*));
		int** dp = (int**)malloc((n+5)*sizeof(int*));
		for (int i=0; i<n+5; ++i) {
			s[i] = (int*)malloc((n+5)*sizeof(int));
			dp[i] = (int*)malloc((n+5)*sizeof(int));
		}

		memset(dp, 0, sizeof(dp));
		memset(s, 0, sizeof(s));

		for (int i=1; i<=n; ++i)
			scanf("%d", &a[i]);

		sum[0] = 0;
		sum[1] = a[1];

		for (int i = 2; i <= n; ++i)
			sum[i] = sum[i-1] + a[i];

		n2_DP(n, s, dp);

		for (int i=0; i<n+5; ++i) {
			free(s[i]);
			free(dp[i]);
		}
		free(s);
		free(dp);
	}

	return 0;
}
