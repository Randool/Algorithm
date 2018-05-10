// http://www.lintcode.com/en/problem/maximal-square/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSquare(vector<vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        if (!m || !n) return 0;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j])
                    matrix[i][j] = 1 + min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1]));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result = max(result, matrix[i][j]);

        return result * result;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
	Solution sol;
	int m, n, t;
	while (cin >> m >> n) {
        vector<vector<int> > matrix(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];
        printf("%d\n", sol.maxSquare(matrix));
	}
	return 0;
}
