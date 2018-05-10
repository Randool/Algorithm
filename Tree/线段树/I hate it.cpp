#include <cstdio>
#include <cstring>
#include <iostream>
#define lson l, m, root<<1
#define rson m+1, r, root<<1|1
#define MAXN 200005<<2
using namespace std;

char q;
int Max[MAXN], n, m, a, b;

void build(int l, int r, int root)
{
    if (l == r) {
        scanf("%d", &Max[root]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    Max[root] = max(Max[root<<1], Max[root<<1|1]);  // PushUp
}

void update(int p, int newScore, int l, int r, int root)
{
    if (l == r) {
        Max[root] = newScore;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, newScore, lson);
    else update(p, newScore, rson);
    Max[root] = max(Max[root<<1], Max[root<<1|1]);  // PushUp
}

int query(int L, int R, int l, int r, int root)
{
    if (L <= l && r <= R) return Max[root];
    int ret = -1;
    int m = (l + r) >> 1;
    if (L <= m) ret = max(ret, query(L, R, lson));
    if (R  > m) ret = max(ret, query(L, R, rson));
    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m))
    {
        memset(Max, 0, sizeof(Max));
        build(1, n, 1);
        for (int i=0; i<m; ++i) {
        	getchar();
            scanf("%c%d%d", &q, &a, &b);
			if (q == 'Q')
                printf("%d\n", query(a, b, 1, n, 1));
            else
                update(a, b, 1, n, 1);
        }
    }
    return 0;
}
