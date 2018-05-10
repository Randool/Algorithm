#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
/*(1 <= N <= 100，1 <= W <= 50000)
(1 <= Wi, Pi <= 10000， 1 <= Ci <= 200)*/
struct Item {
	int w,p;
} item[20005];

long long dp[50005];
void DP(int items, int volume);

int main() {
	int N, W, p, q;
	while(~scanf("%d%d", &N, &W)) { //N为物品的种类，W为背包的容量
		int Pi,Ci,Wi;
		q=0;
		for(int i=1; i<=N; i++) {
			p=1;
			scanf("%d%d%d", &Wi, &Pi, &Ci);
			while(Ci >= p) {
				item[++q].w = p*Wi;
				item[q].p = p*Pi;
				Ci -= p;
				p*=2;
			}
			if(Ci > 0) {
				p=Ci;
				item[++q].w = p*Wi;
				item[q].p = p*Pi;
			}
		}
		//for(int i=1;i<=q;i++)
		//	cout<<item[i].w<<" "<<item[i].p<<endl;
		DP(q, W);
	}
	return 0;
}

void DP(int items, int volume) {
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=items; i++) {
		for(int j=volume; j>=item[i].w; j--)
			dp[j] = max( dp[j], dp[j-item[i].w]+item[i].p );
		/*for(int k=1; k<=volume; k++)
			cout<<dp[k]<<" ";
		cout << endl;*/
	}
	printf("%lld\n",dp[volume]);
}
/*
3 6
2 2 5
3 3 8
1 4 1

9*/
