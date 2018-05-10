#include <cstdio>
#include <iostream>
#define MAXN 50005
#define lson l, m, root<<1
#define rson m+1, r, root<<1|1
using namespace std;

int T, n, Case = 0;
int sum[MAXN << 2];

void build(int l, int r, int root) {
    if (l == r) {
        scanf("%d", &sum[root]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    sum[root] = sum[root<<1] + sum[root<<1|1];  // PushUp
}

void update(int p, int add, int l, int r, int root) {
    if (l == r) {
        sum[root] += add;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, add, lson);
    else update(p, add, rson);
    sum[root] = sum[root<<1] + sum[root<<1|1];  // PushUp
}

int query(int L, int R, int l, int r, int root) {
    if (L <= l && r <= R) return sum[root];
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (m  < R) ret += query(L, R, rson);
    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    char ask[15];
    int a, b;
    scanf("%d", &T);
    while (T--)
    {
        printf("Case %d:\n", ++Case);
        scanf("%d", &n);

        build(1, n, 1);

        while (scanf("%s", &ask))
        {
            if (ask[0] == 'E') break;
            scanf("%d%d", &a, &b);
            if (ask[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
            else if (ask[0] == 'A') update(a, b, 1, n, 1);
            else if (ask[0] == 'S') update(a, -b, 1, n, 1);
        }
    }
    return 0;
}
