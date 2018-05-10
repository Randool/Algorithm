//http://acm.hdu.edu.cn/showproblem.php pid=1232
#include <cstdio>
#include <iostream>
#define MAXN 1001
using namespace std;

int n, m, a, b;
int p[MAXN];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
	while(~scanf("%d", &n), n)
	{
		scanf("%d", &m);
		int ans = n-1;
		for(int i=0; i<=n; i++) p[i] = i;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			int x = find(a);
			int y = find(b);
			if(x != y){
				p[x] = y;
				ans--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
