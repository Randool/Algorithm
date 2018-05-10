// http://www.lintcode.com/en/problem/coins-in-a-line-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool firstWillWin(vector<int> values) {
        if (values.size() <= 2)
            return true;

        int sum = 0, len = values.size();
        vector<int> dp(values.size()+2, 0);

        for (int i=0; i<values.size(); ++i)
            sum += values[i];

        // 定义dp[i]为从i到n的最大取值

        dp[len-1] = values[len-1];
        dp[len-2] = values[len-1] + values[len-2];
        dp[len-3] = values[len-2] + values[len-3];

        for (int i = len-4; i >= 0; --i) {
            int pick1 = values[i] + min(dp[i+2], dp[i+3]);
            int pick2 = values[i] + values[i+1] + min(dp[i+3], dp[i+4]);
            dp[i] = max(pick1, pick2);
        }

        return sum - dp[0] < dp[0];
    }
};

int main() {
    Solution sol;
    int n, k, t;
    while (cin >> n) {
        vector<int> values;

        for (int i=0; i<n; ++i)
            cin >> t, values.push_back(t);

        if (sol.firstWillWin(values)) puts("Yes");
        else puts("No");
    }
    return 0;
}
