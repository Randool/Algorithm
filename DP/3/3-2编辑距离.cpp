#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int LCS(const string &s1, const string &s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[l1+5][l2+5];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= l1; ++i) dp[i][0] = i;
    for (int i = 0; i <= l2; ++i) dp[0][i] = i;

    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[l1][l2];
}

int main() {
    freopen("input.txt", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;

    printf("%d\n", LCS(s1, s2));

    return 0;
}
