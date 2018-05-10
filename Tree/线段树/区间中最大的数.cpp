#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 40005
#define lson l, m, root<<1
#define rson m+1, r, root<<1|1
using namespace std;

int maxNum[MAXN];

void build(int l, int r, int root)
{
    if (l == r) {
        scanf("%d", &maxNum[root]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    maxNum[root] = max(maxNum[root<<1], maxNum[root<<1|1]);
}

int query(int L, int R, int l, int r, int root)
{
    if (L <= l && r <= R)
    {
        return maxNum[root];
    }
    int lmax = 0, rmax = 0;
    int m = (l + r) >> 1;
    if (L <= m) lmax = query(L, R, lson);
    if (m  < R) rmax = query(L, R, rson);
    return max(lmax, rmax);
}

int main()
{
    int N; scanf("%d", &N);
    build(1, N, 1);
    int Q; scanf("%d", &Q);
    for (int i=0; i<Q; ++i)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        printf("%d\n", query(p+1, q+1, 1, N, 1));
    }
    return 0;
}
