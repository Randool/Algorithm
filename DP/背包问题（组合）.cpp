// http://www.lintcode.com/zh-cn/problem/backpack-vi/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int backPackVI(vector<int>& nums, int target) {
        vector<int> dp(target + 5, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i)
            for (int j = 0; j < nums.size(); ++j)
                if (nums[j] <= i)
                    dp[i] += dp[i-nums[j]];
        return dp[target];
    }
};

int main()
{
    Solution sol;
    int n, k, t;
    while (cin >> n >> t) {
        vector<int> nums;
        for (int i=0; i<n; ++i)
            cin >> k, nums.push_back(k);
        cout << sol.backPackVI(nums, t) << endl;
    }

    return 0;
}
