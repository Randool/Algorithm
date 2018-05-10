#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-iii/
     * 最多可以完成两笔交易。
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if (size <= 1) return 0;

        vector<int> profit_front(size, 0);
        for (int i = 1, valley = prices[0]; i < size-1; ++i)
        {
            profit_front[i] = max(profit_front[i-1], prices[i] - valley);
            valley = min(valley, prices[i]);
        }

        vector<int> profit_back(size, 0);
        for (int i = size-2, peak = prices[size-1]; i>=0; --i)
        {
            profit_back[i] = max(profit_back[i+1], peak - prices[i]);
            peak = max(peak, prices[i]);
        }

        int profit = 0;
        for (int i=0; i<size; ++i)
            profit = max(profit, profit_front[i] + profit_back[i]);
        return profit;
    }
};

int main()
{
    Solution sol;

    vector<int> A;
    int n, t;
    while (cin >> n)
    {
        A.clear();
        for (int i=0; i<n; ++i)
            cin >> t, A.push_back(t);
        cout << sol.maxProfit(A) << endl;
    }

    return 0;
}
