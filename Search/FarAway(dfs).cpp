//https://vjudge.net/problem/CSU-1830
#include <cstdio>
#include <vector>
using namespace std;
int T, C, M, mx;
struct Node { int v,w; } temp;
vector<Node> e[100001];

void dfs(int start, int num) {
	for(int i=0, sz = e[start].size(); i < sz; i++) {
		mx = max(mx, num + e[start][i].w);
		dfs(e[start][i].v, num + e[start][i].w);
	}
}

int main () {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&C, &M);
		for(int i=1; i<=C; i++) e[i].clear();
		for(int i=1; i<C; i++) {
			int c1,c2,d;
			scanf("%d%d%d", &c1, &c2, &d);
			temp.v = c2; temp.w = d;
			e[c1].push_back(temp);
		}
		mx = 0;
		dfs(1,0);
		printf("%d\n", mx >= M ? mx : -1);
	}
	return 0;
}
