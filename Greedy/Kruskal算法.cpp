#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXM 50005
#define MAXN 50005
using namespace std;
int N, M, S, E, W;
int r[MAXM], u[MAXM], v[MAXM], w[MAXM]; //第 i条边的两个端点号分别是 u[i] v[i] 权值是 w[i] 
int p[MAXN]; //连通分量的树的父节点 

bool cmp(const int i, const int j) {
	return w[i] < w[j];
}

int find(int x) { //查找 x所在树的根节点 
	return p[x] == x ? x : p[x] = find(p[x]);
}

int Kruskal() {
	int ans = 0;
	for(int i=0; i<N; i++) p[i] = i; // 初始化并查集 
	for(int i=0; i<M; i++) r[i] = i; // 初始化边序号 
	sort(r,r+M,cmp);
	for(int i=0; i<M; i++) {
		int e = r[i];
		int x = find(u[e]);
		int y = find(v[e]);
		if(x != y) {
			ans += w[e];
			p[x] = y;
		}
	}
	return ans;
}

int main() {
	while(~scanf("%d%d",&N,&M)) {
		for(int i=0; i<M; i++)
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
		printf("%d\n", Kruskal());
	}
	return 0;
}
/*
6 10
1 6 1
1 2 17
1 5 16
2 6 11
2 3 6
2 4 5
3 4 10
4 5 4
4 6 14
5 6 33

9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 9 7
2 8 11
3 9 2
7 9 6
3 6 4
4 6 14
1 8 8
*/
