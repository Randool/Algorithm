// http://www.lintcode.com/zh-cn/problem/maximum-product-subarray/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) return 0;
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int end1 = maxEnd * nums[i];
            int end2 = minEnd * nums[i];
            maxEnd = max(max(end1, end2), nums[i]);
            minEnd = min(min(end1, end2), nums[i]);
            result = max(maxEnd, result);
        }
        return result;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    int n, t;
    vector<int> nums;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        nums.push_back(t);
    }
    Solution sol;
    printf("%d\n", sol.maxProduct(nums));

    return 0;
}
