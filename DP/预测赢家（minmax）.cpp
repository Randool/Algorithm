#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int> > dp;
    int Pick(int p, int q, const vector<int> &nums) {
        if (dp[p][q]) return dp[p][q];
        if (p == q) return (dp[p][q] = nums[p]);
        return dp[p][q] = max(nums[p] - Pick(p+1, q, nums), nums[q] - Pick(p, q-1, nums));
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        this->dp = vector<vector<int> > (n+1, vector<int>(n+1, 0));
        return Pick(0, n-1, nums) >= 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, t;
    while (cin >> n) {
        nums.clear();
        while (n--) {
            cin >> t;
            nums.push_back(t);
        }
        if (sol.PredictTheWinner(nums))
            cout << "Can\n";
        else
            cout << "Can't\n";
    }

    return 0;
}
