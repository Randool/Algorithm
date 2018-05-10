#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 505
#define sum(i,j) prefix[j]-prefix[i-1]

int n,m, a[MAXN];
int prefix[MAXN];
int dp[MAXN][MAXN];

void DP() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {

        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        prefix[i] = a[i] + prefix[i-1];
    }

    return 0;
}
