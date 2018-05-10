#include <cstdio>
#include <iostream>
#define MAXN 10005
using namespace std;

int S, n;
int d[MAXN], V[MAXN];
bool vis[MAXN];

int dp_max(int S) {
	int& ans = d[S];
	if(vis[S]) return ans;
	vis[S] = 1;
	ans = -(1<<30);
	for(int i=1; i<=n; i++)
		if(S>=V[i])
			ans = max(ans, dp_max(S-V[i])+1);
	return ans;
}


void print_ans(int* d, int S) {
	for(int i=1; i<=n; i++)
		if(S>=V[i] && d[S]==d[S-V[i]]+1)
		{
			printf("%d ", i);
			print_ans(d, i);
			break;
		}
}

int main() {
	memset(vis,0,sizeof(vis));
	printf("面额之和：");
	scanf("%d", &S);
	printf("面额种类：");
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &V[i]);
	for(int )
	printf("最长：%d\n", dp_max(S));
	print_ans(d, S);

	system("pause");
	return 0;
}
