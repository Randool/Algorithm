//http://www.lintcode.com/zh-cn/problem/maximal-rectangle/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // n^3
    int maximalRectangle(vector<vector<bool> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), _max = 0;
        int prefix[m+1][n+1];
        memset(prefix, 0 , sizeof(prefix));

        for (int j = 0; j < n; ++j)
            prefix[1][j] = matrix[0][j] ? 1 : 0;

        for (int j = 0; j < n; ++j)
            for (int i = 1; i < m; ++i)
                prefix[i+1][j] = prefix[i][j] + (matrix[i][j] ? 1 : 0);

        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                int predict = j - i + 1, len = 0;
                for (int k = 0; k < n; ++k) {
                    int cur = prefix[j+1][k] - prefix[i][k];
                    if (cur != predict) len = 0;
                    else {
                        ++len;
                        _max = max(_max, len*predict);
                    }
                }
            }
        }
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
