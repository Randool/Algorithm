#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 110
using namespace std;

int n, m, p[MAXN];
struct Node {
	int a, b, value;
} node[MAXN*MAXN/2];

bool cmp(const Node a, const Node b) { return a.value < b.value; }

int Find(int n) { return n == p[n] ? n : p[n] = Find(p[n]); }

int Kruskal()
{
    int ans = 0, cnt = 0, i = 0;;
    sort(node, node+m, cmp);

    while (cnt < n && i<m)
    {
        int x = Find(node[i].a);
        int y = Find(node[i].b);
        if (x != y) {
            p[x] = y;
            ++ cnt;
            ans += node[i].value;
        }
        ++i;
    }

    return ans;
}

int main()
{
    while(~scanf("%d", &n), n)
    {
        m = n * (n-1) / 2;
        for (int i=1; i<=n; ++i)
            p[i] = i;

        for (int i=0; i<m; ++i)
            scanf("%d%d%d", &node[i].a, &node[i].b, &node[i].value);

        printf("%d\n", Kruskal());
    }
    return 0;
}
