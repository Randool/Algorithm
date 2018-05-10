#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

bool vis[1e7];

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m)==2)
	{
		memset(vis,0,sizeof(vis));
		int t = sqrt(m+0.5);
		// O(nlog(n))
		for(int i=2; i<=t; i++)
			for(int j=i*i; j<=m; j++)
				vis[j] = 1;
	}
	return 0;
}
