#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 2005
#define INF 1010
using namespace std;

char ss[MAXN];
int dp[MAXN];
int len;

bool rever(int l, int r) {
	int p=l, q=r;
	while(p<=q) {
		if(ss[p]!=ss[q])
			return 0;
		p++;
		q--;
	}
	return 1;
}

int main()
{
    freopen("in.txt", "r", stdin);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", ss+1);
		len = strlen(ss+1);
		for(int i=0; i<=len; i++)
			dp[i] = i==0 ? 0 : INF;

		for(int i=1; i<=len; i++)
			for(int j=1; j<=i; j++)
				if(rever(j,i))
					dp[i] = min(dp[i], dp[j-1]+1);
		printf("%d\n", dp[len]);
	}
	return 0;
}
