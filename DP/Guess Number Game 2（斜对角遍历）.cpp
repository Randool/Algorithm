// http://www.lintcode.com/zh-cn/problem/guess-number-game-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int> > dp;
public:
    /**
     * @param n an integer
     * @return how much money you need to have to guarantee a win
     */
    int getMoneyAmount(int n) {
        dp = vector<vector<int> > (n+1, vector<int>(n+1, 0));
        for (int i = 1; i < n; ++i) dp[i][i+1] = i;

        for (int len = 2; len <= n-1; ++len) {
            for (int index = 1; index+len <= n; ++index) {
                int _min = INT_MAX;
                for (int k = index + 1; k < index+len; ++k)
                    _min = min(_min, k + max(dp[index][k-1], dp[k+1][index+len]));
                dp[index][index+len] = _min;
            }
        }
        return dp[1][n];
    }
};

int main()
{
    Solution sol;
    int n;
    while (cin >> n) {
        cout << sol.getMoneyAmount(n) << endl;
    }
    return 0;
}
