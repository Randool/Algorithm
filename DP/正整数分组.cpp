#include <iostream>
#include <cstring>
using namespace std;

int num[105];
//int dp[2][5005];
int dp[105][5005];

int main() {
	int N, sum;
	while(scanf("%d",&N)==1) {
		sum = 0;
		memset(num,0,sizeof(num));

		int p = 0, q = 1;//滚动数组标签 

		for(int i=1; i<=N; i++) {
			scanf("%d", &num[i]);
			sum += num[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=sum/2; j++) {
				if(num[i] > j)
					dp[q][j] = dp[p][j];
				else if(num[i] <= j)
					dp[q][j] = max(dp[p][j], dp[p][j-num[i]]+num[i]);

				//cout << dp[q][j] << " ";
			}
			//cout << endl;
			swap(p,q);
		}
		printf("%d\n", sum-2*dp[p][sum/2]);
	}
	return 0;
}
