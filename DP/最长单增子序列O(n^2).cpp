#include <iostream>
#include <cstdio>
#include <cstring>
const int maxn = 50005;
using namespace std;
int S[2][maxn];
int main() {
	int N, i, j, t;
	while(scanf("%d",&N)!=EOF) {
		memset(S,0,sizeof(S)); S[1][1] = 1;
		for(i=1; i<=N; i++)
			scanf("%d",&S[0][i]);
		for(i=2; i<=N; i++) {
			t=0;
			for(j=i-1; j>=1; j--) {
				if(S[0][i]>S[0][j] && S[1][j]>t)
					t=S[1][j];
				S[1][i] = t+1;
			}
		}
		t=0;
		for(i=1; i<=N; i++)
			t=max(t,S[1][i]);
		printf("%d\n",t);
	}
	return 0;
}
