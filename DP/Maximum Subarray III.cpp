// http://www.lintcode.com/en/problem/maximum-subarray-iii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int> > dp;
public:
    int maxSubArray(vector<int> nums, int k) {
        const int n = nums.size();

        dp = vector<vector<int> > (n+1, vector<int> (k+1, INT_MIN));

        for (int i = 0; i <= n; ++i) dp[i][0] = 0;

        // dp[i][j] = max{dp[p][j-1] + maxSubArray(p+1, i)}
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                int tmp = 0;
                for (int t = i-1; t >= j-1; --t) {
                    tmp = max(tmp+nums[t], nums[t]);
                    dp[i][j] = max(dp[i][j], tmp + dp[t][j-1]);
                }
            }
        }
        return dp[n][k];
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    Solution sol;
    int n, k, t;
    while (cin >> n >> k) {
        vector<int> nums;
        while (n--) cin >> t, nums.push_back(t);
        cout << sol.maxSubArray(nums, k) << endl;
    }
    return 0;
}
/*
3 2
-1 0 -1

6 2
-1 4 -2 3 -2 3

9 1
-5 6 2 -3 1 -7 9 -2 11

9 2
-5 6 2 -3 1 -7 9 -2 11

*/
