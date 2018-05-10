// http://www.lintcode.com/zh-cn/problem/house-robber/
// http://www.lintcode.com/zh-cn/problem/house-robber-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long houseRobber(vector<int> &A) {
        typedef long long LL;
        LL dp[A.size()+5];

        if (A.empty()) return (LL)0;
        if (A.size() == 1) return (LL)A[0];

        dp[0] = (LL)A[0];
        dp[1] = max((LL)A[0], (LL)A[1]);

        for (int i = 2; i < A.size(); ++i)
            dp[i] = max(dp[i-1], (LL)(dp[i-2] + A[i]));

        return dp[A.size()-1];
    }

    // »·ÐÎDP
    int houseRobber2(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int dp[nums.size()+5][2];

        memset(dp, 0, sizeof(dp));

        dp[1][0] = nums[0], dp[2][1] = nums[1];

        for (int i = 2; i < nums.size(); ++i)
            dp[i][0] = max(dp[i-1][0], dp[i-2][0]+nums[i-1]);
        for (int i = 3; i <= nums.size(); ++i)
            dp[i][1] = max(dp[i-1][1], dp[i-2][1]+nums[i-1]);

        return max(dp[nums.size()-1][0], dp[nums.size()][1]);
    }
};

int main()
{
    Solution sol;
    int n, t;
    while (cin >> n) {
        vector<int> A;
        for (int i = 0; i < n; ++i)
            cin >> t, A.push_back(t);
        cout << sol.houseRobber(A) << endl;
    }

    return 0;
}
