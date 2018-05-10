//http://www.lintcode.com/zh-cn/problem/maximal-rectangle/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getLayerMax(vector<int> &height) {
        int _max = 0, size = height.size();
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[i] <= height[s.top()]) {
                int cur = s.top();
                s.pop();
                if (s.empty()) _max = max(_max, height[cur]*i);
                else _max = max(_max, height[cur]*(i-s.top()-1));
            }
            s.push(i);
        }
        return _max;
    }
public:
    int maximalRectangle(vector<vector<bool> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), _max = 0;

        vector<vector<int> > prefix(m, vector<int>(n, 0));

        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                if (!matrix[i][j]) prefix[i][j] = 0;
                else prefix[i][j] = (i==0) ? 1 : prefix[i-1][j] + 1;

        for (int i = 0; i < m; ++i) _max = max(_max, getLayerMax(prefix[i]));

        return _max;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
	Solution sol;
	int m, n, t;
	while (cin >> m >> n) {
        vector<vector<bool> > matrix(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &t);
                matrix[i][j] = t == 1 ? true : false;
            }
        }
        printf("%d\n", sol.maximalRectangle(matrix));
	}
	return 0;
}
