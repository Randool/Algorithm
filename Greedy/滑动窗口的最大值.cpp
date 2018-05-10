#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> Q;

        if (k >= nums.size()) {
            int _max = -0x3f3f3f3f;
            for (int i = 0; i < nums.size(); ++i)
                _max = max(_max, nums[i]);
            result.push_back(_max);
            return result;
        }

        for (int i = 0; i < k-1; ++i) {
            while (!Q.empty() && Q.back() < nums[i]) {
                Q.pop_back();
            }
            Q.push_back(nums[i]);
        }

        for (int i=k-1; i<nums.size(); ++i)
        {
            while (!Q.empty() && Q.back() < nums[i]) {
                Q.pop_back();
            }
            Q.push_back(nums[i]);

            result.push_back(Q.front());

            if (Q.front() == nums[i-k+1])
                Q.pop_front();
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int n, k, t;
    vector<int> nums;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        nums.push_back(t);
    }
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    for (int i=0; i<ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}
/*
9 10
1 2 3 1 4 5 2 3 6
*/
