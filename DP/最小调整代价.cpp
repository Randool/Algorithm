// http://www.lintcode.com/zh-cn/problem/minimum-adjustment-cost/
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
private:
    const int MAXN = 0x3f3f3f3f;
    int **dp;    // 定义 dp[i][j] 为调整第 i 个数为 j 的最小代价
    void make_dp_array(int n) {
        dp = new int *[n+5];
        for (int i = 0; i < n+1; ++i)
            dp[i] = new int [105] ();
    }
public:
    int MinAdjustmentCost(vector<int> &A, int target) {
        int n = A.size();
        if (n < 2) return 0;
        make_dp_array(n);
        for (int i = 1; i < 101; ++i)
            dp[0][i] = abs(i - A[0]);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < 101; ++j) {
                dp[i][j] = MAXN;
                int diff = abs(j - A[i]);
                for (int k = max(1, j - target); k <= min(100, j + target); ++k)
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + diff);
            }
        }
        int result = MAXN;
        for (int i = 1; i <= 100; ++i)
            result = min(result, dp[n-1][i]);
        return result;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    int n, t, tar;
    scanf("%d%d", &n, &tar);
    vector<int> A;
    for (int i = 0; i < n; ++i)
        scanf("%d", &t), A.push_back(t);

    Solution sol;
    printf("%d\n", sol.MinAdjustmentCost(A, tar));

    return 0;
}
