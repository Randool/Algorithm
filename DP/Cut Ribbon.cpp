#include <cstdio>
#include <cstring>
using namespace std;
int a[3];
int dp[4005];
int max(int a,int b) {
	return a > b ? a : b;
}
void Show(int n) {
	for(int i=0; i<=n; i++) {
		printf("%d ",dp[i]);
	}
	printf("\n");
}
int main() {
	int n;
	while(~scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2])) {
		memset(dp,-1, sizeof(dp));
		dp[0] = 0;
		for(int i=0; i<3; i++) {
			int m = n-a[i];

			for(int j=0; j<=m; j++) {
				if(dp[j]>=0)
					dp[j+a[i]] = max(dp[j+a[i]],dp[j]+1);
			}
			//Show(n);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
