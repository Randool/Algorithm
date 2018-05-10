// http://www.lintcode.com/en/problem/subsets/
// n*2^n
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<int> layer;
	void backtrack(vector<vector<int> > &result, vector<int> &nums, int cur) {
	    result.push_back(layer);
	    for (int i=cur; i<nums.size(); ++i) {
            layer.push_back(nums[i]);
            backtrack(result, nums, i+1);
            layer.pop_back();
        }
	}

	void backtrack2(vector<vector<int> > &result, const vector<int> source, int cur)
	{
        result.push_back(layer);
        for (int i=cur; i<source.size(); ++i)
        {
            if (i != cur && source[i-1] == source[i])
                continue;
            layer.push_back(source[i]);
            backtrack2(result, source, i+1);
            layer.pop_back();
        }
	}
public:
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // Unique subsets
        vector<vector<int> > result;
        if (S.empty()) {
            result.push_back(layer);
            return result;
        }
        vector<int> source(S);
        sort(source.begin(), source.end());
        backtrack2(result, source, 0);

        return result;
    }

	vector<vector<int> > subsets(vector<int> &nums) {
	    /**
	 * @param S: A set of numbers.
	 * @return: A list of lists. All valid subsets.
	 */
		vector<vector<int> > result;
		if (!nums.size()) {
            result.push_back(layer);
            return result;
		}
		sort(nums.begin(), nums.end());

		for (int i=0; i<pow(2, nums.size()); ++i) {
			vector<int> tmp;
			for (int j=0; j<nums.size(); ++j) {
				if (i & (1 << j)) {
					tmp.push_back(nums[j]);
				}
			}
			result.push_back(tmp);
		}
		return result;
	}

	vector<vector<int> > subsets2(vector<int> &nums) { // Using backtrack
        vector<vector<int> > result;
        if (nums.empty()) {
            return result;
        }
        sort(nums.begin(), nums.end());
        backtrack(result, nums, 0);

        return result;
	}
};


int main() {
	int n, m;
	vector<int> nums;
	cin >> n;

	while (n--) cin >> m, nums.push_back(m);

	Solution sol;
	vector<vector<int> > result = sol.subsetsWithDup(nums);

	for (int i=0; i<result.size(); ++i) {
		for (int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}
