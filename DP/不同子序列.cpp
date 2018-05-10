// http://www.lintcode.com/zh-cn/problem/distinct-subsequences/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string &S, string &T) {
        if (T.empty()) return 1;
        if (S.length() < T.length() || T.empty()) return 0;

        int dp[S.length()+5][T.length()+5];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < S.length(); ++i) dp[i][0] = 1;

        for (int i = 1; i <= S.length(); ++i) {
            for (int j = 1; j <= T.length(); ++j) {
                dp[i][j] = dp[i-1][j] + S[i-1] == T[j-1] ? dp[i-1][j] : 0;
            }
        }

        return dp[S.length()][T.length()];
    }
};
/*
conatrtraa contra
6
ctrtraar ctra
*/
int main()
{
    Solution sol;
    string s, t;
    while (cin >> s >> t) {
        cout << sol.numDistinct(s, t) << endl;
    }

    return 0;
}
