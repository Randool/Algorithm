// http://www.lintcode.com/en/problem/maximum-subarray-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int *leftMax = NULL;
    int *rightMax = NULL;
public:
    int maxTwoSubArrays(vector<int> &nums) {
        if (nums.empty()) return 0;
        int size = nums.size(), temp;

        leftMax = new int[size+1];
        rightMax = new int[size+1];

        leftMax[0] = temp = nums[0];
        for (int i = 1; i < size; ++i) {
            if (temp < 0) temp = 0;
            temp += nums[i];
            leftMax[i] = max(leftMax[i-1], temp);
        }

        rightMax[size-1] = temp = nums[size-1];
        for (int i = size-2; i >= 0; --i) {
            if (temp < 0) temp = 0;
            temp += nums[i];
            rightMax[i] = max(rightMax[i+1], temp);
        }

        temp = INT_MIN;
        for (int i = 0; i < size-1; ++i)
            temp = max(temp, leftMax[i] + rightMax[i+1]);

        return temp;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    Solution sol;
    int n, k, t;
    while (cin >> n) {
        vector<int> nums;
        while (n--) cin >> t, nums.push_back(t);
        cout << sol.maxTwoSubArrays(nums) << endl;
    }
    return 0;
}
