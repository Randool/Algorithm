//http://acm.hdu.edu.cn/showproblem.php pid=1863
#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 105
using namespace std;

int n, m, a, b, c;
int p[MAXN]; //并查集
bool r[MAXN]; // 边序号
struct Node {
	int a, b, value;
} node[1005];

bool cmp(const Node a, const Node b) {
	return a.value < b.value;
}

int find(int n) {
	return p[n]==n ? n : find(p[n]);
}

int Kruskal() {
	int ans = 0;
	sort(node, node+n, cmp);
	for(int i=0; i<n; i++)
	{
		int e = node[i].value;
		int a = find(node[i].a);
		int b = find(node[i].b);
		if(a != b) {
			ans += e;
			p[a] = b;
		}
	}
	int flag = 1, r = find(1), s;
	for(int i=2; i<=m; i++) //检查是否所有的点都在集合中
	{
		s = find(i);
		if(r != s) flag = 0;
	}

	if(flag)
		printf("%d\n", ans);
	else
		printf("?\n");
}

int main() {
	while(~scanf("%d",&n), n) { //道路数
		scanf("%d", &m); //村庄数

		for(int i=0; i<=m; i++) {
			p[i] = i;
			r[i] = 0;
		}

		for(int i=0; i<n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			node[i].a = a;
			node[i].b = b;
			node[i].value = c;
		}
		Kruskal();
	}
	return 0;
}
/*
5 5
1 2 3
2 1 4
3 4 1
4 3 2
4 5 4
*/
