// http://www.lintcode.com/zh-cn/problem/paint-fence/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * dp[i] = dp[i-1] * (k-1) + dp[i-2] * (k-1);
     */
    int numWays(int n, int k) {
        if (!n || !k) return 0;
        if (n == 1) return k;
        if (n == 2) return k*k;
        int pre = k, now = k*k;
        for (int i = 3; i <= n; ++i) {
            int tmp = now;
            now = (pre + now) * (k-1);
            pre = tmp;
        }
        return now;
    }
};

int main()
{
    Solution sol;
    int n, k;
    while (cin >> n >> k)
    {
        cout << sol.numWays(n, k) << endl;
    }

    return 0;
}
