#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int n, A[20];
bool isp[50], vis[50];

bool prime(int n) {
	int temp = sqrt(n)+1;
	for(int i=2; i<=temp; i++)
		if(n%i==0)
			return 0;
	return 1;
}

void dfs(int cur) {
	if(cur > n && isp[A[1]+A[n]]) {
		for(int i=1; i<=n; i++) {
			printf("%d", A[i]);
			if(i==n) printf("\n");
			else printf(" ");
		}
	} else
		for(int i=2; i<=n; i++) {
			if(!vis[i] && isp[i+A[cur-1]]) {
				vis[i]=1;
				A[cur] = i;
				dfs(cur+1);
				vis[i]=0;
			}
		}
}

int main() {
	int Case = 0;
	memset(isp,0,sizeof(isp));
	for(int i=3; i<=50; i+=2)
		isp[i] = prime(i);
	A[1]=1;
	while(~scanf("%d",&n)) {
		printf("Case %d:\n", ++Case);
		if(n%2==1) {
			printf("None\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		dfs(2);
		printf("\n");
	}
	return 0;
}
