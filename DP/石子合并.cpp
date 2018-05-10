#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 205
#define INF 0x3f3f3f3f
using namespace std;

int n;
int a[MAXN];
int sum[MAXN];
int s[MAXN][MAXN];
int dp[MAXN][MAXN];

void Show(int dp[][MAXN], int n) {
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j)
			if (j<=i) printf("%3d ", 0);
			else printf("%3d ", dp[i][j]);
		printf("\n");
	}
}

void n3_DP(int n) {
	int i, j, k, len;
	for (i=1; i<=n; ++i)
		dp[i][i] = 0;

	for (len=2; len<=n; ++len) { // 合并数量
		for (i=1; i<=n; ++i) {
			j = i + len - 1;
			int tmp = INF;
			int s = sum[j] - sum[i-1];
			for (k=i; k<j; ++k) {
				tmp = min(tmp, dp[i][k]+dp[k+1][j]+s);
			}
			dp[i][j] = tmp;
		}
	}
	//Show(n);
	printf("%d\n", dp[1][n]);
}

void n2_DP(int n) {
	int i, j, k, len, tmp, end;
	for (i=1; i<=n; ++i) {
		dp[i][i] = 0;
		s[i][i] = i;
	}
	// 平行四边形优化
	for (len=2; len<=n; ++len) {
		for (i=1; i<=n-len+1; ++i) {
			int end = i+len-1;
			tmp = INF;
			k = 0;
			printf("len=%d i=%d end=%d\n", len, i, end);
			for (j=s[i][end-1]; j<=s[i+1][end]; ++j)
			{
				printf("  j = %d to %d\n", s[i][end-1], s[i+1][end]);
				if (dp[i][j] + dp[j+1][end] + sum[end]-sum[i-1] < tmp) {
					tmp = dp[i][j] + dp[j+1][end] + sum[end]-sum[i-1];
					k = j;
				}
			}
			dp[i][end] = tmp;
			s[i][end] = k;
		}
	}
	printf("s:\n");
	Show(s, n);
	printf("dp:\n");
	Show(dp, n);
	printf("%d\n", dp[1][n]);
}

int main() {
	freopen("in.txt", "r", stdin);
	while(~scanf("%d", &n)) {

		memset(dp, 0, sizeof(dp));
		memset(s, 0, sizeof(s));

		for (int i=1; i<=n; ++i)
			scanf("%d", &a[i]);

		sum[0] = 0;
		sum[1] = a[1];

		for (int i=2; i<=n; ++i)
			sum[i] = sum[i-1] + a[i];

		n2_DP(n);
	}

	return 0;
}
