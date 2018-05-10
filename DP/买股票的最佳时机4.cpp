#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-iv/
     * 最多可以完成 k 笔交易
     * @param : An integer
     * @param : An integer array
     * @return: Maximum profit
     */
    int maxProfit(int K, vector<int> prices) {
        int n = prices.size();
        if (!K || n <= 1) return 0;

        if (K >= n/2)
        {
            // 任意次买卖
            int ans = 0;
            for (int i=1; i<n; ++i)
                if (prices[i] - prices[i-1] > 0)
                    ans += prices[i] - prices[i-1];
            return ans;
        }

        else
        {
            // DP
            prices.insert(prices.begin(), prices[0]);

            int f[2][n+5], index = 0;
            memset(f, 0, sizeof(f));

            for (int j=1; j<=K; ++j)
            {
                int max_cur = INT_MIN;
                for (int i=1; i<=n; ++i)
                {
                    f[index][i] = max(f[1-index][i], f[][]);
                }
                index = 1 - index;
            }
        }

        return f[1-index][n];
    }
};

int main()
{
    Solution sol;

    vector<int> A;
    int n, t, k;
    while (cin >> n >> k)
    {
        A.clear();
        for (int i=0; i<n; ++i)
            cin >> t, A.push_back(t);;
        cout << sol.maxProfit(k, A) << endl;
    }

    return 0;
}
