// http://www.lintcode.com/zh-cn/problem/edit-distance/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool minDistance(const string& s, const string& t) {
        int m = s.length(), n = t.length();
        if (abs(m - n) > 1) return false;

        int index = 1;
        int dp[2][n+5];
        for (int i = 0; i <= n; ++i) dp[0][i] = i;

        for (int i = 1; i <= m; ++i) {
            dp[index][0] = i;
            for (int j = 1; j <= n; ++j) {
                int t1 = dp[1-index][j-1] + (s[i-1] == t[j-1] ? 0 : 1);
                int t2 = min(dp[index][j-1], dp[1-index][j]) + 1;
                dp[index][j] = min(t1, t2);
            }
            index = 1 - index;
        }

        return dp[1-index][n];
    }
};

int main()
{
    Solution sol;
    string s, t;
    while (cin >> s >> t) {
        cout << sol.minDistance(s, t) << endl;
    }

    return 0;
}
