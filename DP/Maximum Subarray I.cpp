// http://www.lintcode.com/en/problem/maximum-subarray-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // find a contiguous subarray which has the largest sum
    int maxOneSubArray(vector<int> nums) {
        if (nums.empty()) return 0;
        int size = nums.size(), _max = INT_MIN, cur = 0;

        for (int i = 0; i < size; ++i) {
            if (cur < 0) cur = 0;
            cur += nums[i];
            _max = max(_max, cur);
        }
        return _max;
    }
};

int main() {
    Solution sol;
    int n, k, t;
    while (cin >> n >> k) {
        vector<int> nums;
        while (n--) cin >> t, nums.push_back(t);
        cout << sol.maxSubArray(nums, k) << endl;
    }
    return 0;
}
