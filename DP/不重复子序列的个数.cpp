#include <cstdio>
#include <cstring>
const int MAXN = 100005; // 100000

int a[MAXN];//a[i][0]表示数值，a[i][1]表示该数值的前导位
long long Mod = 1e9+7;
int have[MAXN];
long long dp[MAXN];

int main() {
	int N;
	while(~scanf("%d", &N)) {
		dp[0]=1;
		memset(have,0,sizeof(have));
		for(int i=1; i<=N; i++) {
			scanf("%d", &a[i]);
			if( have[a[i]] == 0 )
				dp[i] = (dp[i-1]<<1) % Mod;
			else
				dp[i] = ( (dp[i-1]<<1) - dp[ have[a[i]]-1 ] + Mod ) % Mod;
			have[a[i]] = i;
		}
		long long ans = dp[N] - 1;
		printf("%ld\n", ans);
	}
	return 0;
}
