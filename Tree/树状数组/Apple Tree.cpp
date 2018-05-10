// https://cn.vjudge.net/problem/POJ-3321
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100005
#define lowbit(x) x&(-x)
using namespace std;

char c;
int n, m, u, v, a, total;
struct Node{
    int val, mx;
} node[MAXN];
int cnt[MAXN];
bool apple[MAXN];
vector<vector<int> > root(MAXN);

void make_tree(int r) {
    node[r].val = total;
    for (int i=0; i<root[r].size(); ++i) {
        total++;
        make_tree(root[r][i]);
    }
    node[r].mx = total;
}

void update(int x, int t) {
    while (x <= n) {
        cnt[x] += t;
        x += lowbit(x);
    }
}

int getSum(int x) {
    int result = 0;
    while (x) {
        result += cnt[x];
        x -= lowbit(x);
    }
    return result;
}

int main()
{
    freopen("in.txt", "r", stdin);
    while(~scanf("%d", &n))
    {
        memset(cnt, 0, sizeof(cnt));
        memset(node, 0, sizeof(node));
        for (int i=0; i<root.size(); ++i)
            root[i].clear();

        for (int i=1; i<n; ++i) {
            scanf("%d%d", &u, &v);
            root[u].push_back(v);
        }

        total = 1;
        make_tree(1);

        for (int i=1; i<=n; ++i)
			apple[i] = 1, update(i, 1);

        scanf("%d", &m); getchar();
        while (m--)
        {
            scanf("%c %d", &c, &a), getchar();
            if (c == 'Q') {
                printf("%d~%d = %d\n", node[a].val-1, node[a].mx, 
								getSum(node[a].mx) - getSum(node[a].val-1));
            }
            else {
                if (apple[a]) update(a, -1);
                else update(a, 1);
                apple[a] = !apple[a];
            }
        }
    }

    return 0;
}
