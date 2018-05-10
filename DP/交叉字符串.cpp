#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isInterleave(string &s1, string &s2, string &s3) {
		int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
		if (l1 + l2 != l3) return false;

		bool dp[l1+2][l2+2];
		dp[0][0] = 1;

		for (int i = 1; i <= l1; ++i) dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
		for (int j = 1; j <= l2; ++j) dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];

		for (int i = 1; i <= l1; ++i) {
			for (int j = 1; j <= l2; ++j) {
				dp[i][j] = false;
				int k = i + j - 1;
				dp[i][j] = dp[i-1][j] && s3[k] == s1[i-1] || dp[i][j-1] && s3[k] == s2[j-1];
			}
		}

		return dp[l1][l2];
	}
};

int main() {
	Solution sol;
	string s1 = "aabcc", s2 = "dbbca", s3 = "adabbbccac";
	if (sol.isInterleave(s1,s2,s3)) puts("Yes");
	else puts("No");
	//}
	return 0;
}
