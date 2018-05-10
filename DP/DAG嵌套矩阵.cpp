#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1005
using namespace std;

bool G[MAXN][MAXN];
int d[MAXN], T, n, MAX;
struct Node {
	int a, b, num;
} s[1005];

bool cmp(const Node a, const Node b) {
	if(a.a < b.a && a.b < b.b)
		return 1;
	else
		return 0;
}

int dp(int i) {
	int& ans = d[i];
	if(ans > 0)
		return ans;
	ans = 1;
	for(int j=1; j<=n; j++)
		if(G[i][j])
			ans = max(ans, dp(j)+1);
	return ans;
}

int sum=1,  ans=1;
int dfs(int t) {
	for(int i=1; i<=n; i++) {
		if(G[t][i]) {
			sum++;
			ans = max(ans, sum);
			dfs(i);
			sum--;
		}
	}
	return ans;
}

void print_ans(int i) {
	printf("%d ", i);
	for(int j=1; j<=n; j++) 
		if(G[i][j] && d[i]==d[j]+1) {
			print_ans(j);
			break;
		}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &s[i].a, &s[i].b);
			if(s[i].a > s[i].b)
				swap(s[i].a, s[i].b);
			s[i].num = 1+i;
		}

		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if((s[i].a < s[j].a && s[i].b < s[j].b))
					G[i][j] = 1;
				else
					G[i][j] = 0;
			}

		int ans = 0;
		for(int i=1; i<=n; i++) {
			d[i] = dp(i);
			ans = max(ans, d[i]);
		}
		printf("dp : %d\n", ans);
		ans = 0;
		memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++) {
			d[i] = dfs(i);
			if(ans < d[i]) {
				ans = d[i];
				MAX = i;
			}
		}
		printf("mine : %d\n", ans);
		printf("最长路径是：");
		print_ans(MAX);
	}
	return 0;
}

/*
1
5
1 1
2 3
4 5
6 7
8 9

1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
*/
