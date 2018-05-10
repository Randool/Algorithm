#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 105
#define INF 0x7fffffff
#define _INF -INF
#define C(i,j) cost[j]-cost[i-1]

int n, t;
int a[MAXN];
int cost[MAXN];
int dp[MAXN][MAXN];

void Init() {}

int min( const int a, const int b ) { return a<b ? a : b; }
int max( const int a, const int b ) { return a<b ? b : a; }

int DP( const int set_INF, int (*func) (const int a1, const int a2) )
{
    for (int len = 2; len <= n; ++len) {
        int lim = n + 1 - len;

        for (int begin = 1; begin <= lim; ++begin) {
            int end = begin + len - 1;
            int tmp = set_INF;

            for (int k = begin; k < end; ++k)
                tmp = func(tmp, dp[begin][k] + dp[k+1][end]);

            dp[begin][end] = tmp + C(begin, end);
        }
    }
    return dp[1][n];
}

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cost[i] = cost[i-1] + a[i];
    }

    printf("%d\n%d\n", DP(INF, min), DP(_INF, max));

    return 0;
}
