#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 205
#define INF 0x7fffffff

int n, dp[MAXN];
int r[MAXN][MAXN];

void DP() {
    for (int j = 2; j <= n; ++j) {
        int tmp = INF;
        for (int i = 1; i < j; ++i) {
            int sum = dp[i] + r[i][j];
            tmp = tmp < sum ? tmp : sum;
        }
        dp[j] = tmp;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            scanf("%d", &r[i][j]);
        }
    }

    DP();
    printf("%d\n", dp[n]);

    return 0;
}
