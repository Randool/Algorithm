// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1640
#include <bits/stdc++.h>
using namespace std;
#define MAXN  100005
#define MAXM 200005
typedef long long LL;

int n, m, s, e, cnt;
LL w, top, result;
int P[MAXN];
struct Edge{
    int s, e;
	LL w;
} edges[MAXM];

int Find(int n) { return (P[n] == n) ? n : P[n] = Find(P[n]); }

void __init__(int n) { for (int i = 1; i <= n; ++i) P[i] = i; }

bool cmp1(const Edge &a, const Edge &b) { return a.w < b.w; }
bool cmp2(const Edge &a, const Edge &b) { return a.w > b.w; }

int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    __init__(n);
    for (int i = 0; i < m; ++i)
        scanf("%d%d%lld", &edges[i].s, &edges[i].e, &edges[i].w);
    sort(edges, edges+m, cmp1);

    top = 0;
    cnt = 0;
    for (int i = 0; i < m; ++i) {
        int x = Find(edges[i].s);
        int y = Find(edges[i].e);
        if (x != y) {
            P[x] = y;
            if (top < edges[i].w) {
                top = edges[i].w;
            }
            if (++cnt == n-1) break;
        }
    }

    __init__(n);
    sort(edges, edges+m, cmp2);

    result = 0; cnt = 0;
    for (int i = 0; i < m; ++i) {
        int x = Find(edges[i].s);
        int y = Find(edges[i].e);
        if (x != y && edges[i].w <= top) {
            P[x] = y;
            result += edges[i].w;
            if (++cnt == n-1) break;
        }
    }
    printf("%lld\n", result);

    return 0;
}
