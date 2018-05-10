#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define MAXN 40
using namespace std;

int n;
int c[25];
bool usd[25];
bool prime[MAXN];

bool Prime(int n) {
	for (int i=2; i<=sqrt(n)+1; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
void Init() {
	prime[1] = 0;
	prime[2] = 1;
	for (int i=3; i<MAXN; i++) {
		if (Prime(i)) prime[i] = 1;
		else prime[i] = 0;
	}
}

void DFS(int t) {
	if (t>n && prime[c[1]+c[n]]) {
		for (int i=1; i<=n; i++) {
			printf("%d", c[i]);
			if (i==n) printf("\n");
			else printf(" ");
		}
	}

	else {
		for (int i=2; i<=n; i++) {
			if (!usd[i] && prime[i+c[t-1]] ) {
				usd[i] = 1;
				c[t] = i;
				DFS(t+1);
				usd[i] = 0;
			}
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	Init();
	int Case = 0;

	while(~scanf("%d", &n))
	{
		printf("Case %d:\n", ++Case);
		if (n % 2) {
			printf("\n");
			continue;
		}
		memset(c, 0, sizeof(c));
		memset(usd,0,sizeof(usd));
		c[1] = 1;

		DFS(2);
		printf("\n");
	}
	return 0;
}
