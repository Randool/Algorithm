#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 25
#define INF 0x3fffffff

struct Point {
    double x, y;
} ps[MAXN];

bool cmp(const Point &a, const Point &b) {
    return a.x < b.x;
}

double dist(const Point &a, const Point &b) {
    double dx = a.x-b.x, dy = a.y-b.y;
    return sqrt(dx*dx + dy*dy);
}

double dis[MAXN][MAXN];	// 表示距离
double dp[MAXN][MAXN];	// 记录状态量

double DP(int n) {
    dp[1][2] = dis[1][2];
    for (int j = 3; j <= n; ++j) {
        // i < j-1 的情况
        for (int i = 1; i <= j-2; ++i) {
            dp[i][j] = dp[i][j-1] + dis[j-1][j];
        }

        // i == j-1 的情况
        dp[j-1][j] = INF;
        for (int k = 1; k <= j-2; ++k) {
            dp[j-1][j] = min(dp[k][j-1]+dis[k][j], dp[j-1][j]);
        }
    }
    dp[n][n] = dp[n-1][n] + dis[n-1][n];
    return dp[n][n];
}

int main() {
	// 文件读取
    freopen("input.txt", "r", stdin);
    // 文件输出
	freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &ps[i].x, &ps[i].y);
    }
    sort(ps, ps+n, cmp);

    for (int j = 2; j <= n; ++j)
        for (int i = 1; i < j; ++i)
            dis[i][j] = dist(ps[i], ps[j]);

    printf("%.2lf\n", DP(n));

    return 0;
}
