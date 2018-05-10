#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 55
#define INF 0x3f3f3f3f
using namespace std;

int G[MAXN][MAXN];
int dp[MAXN];

int MaxSum1(int m, int* tmp, int* dp)
{
    int sum = -INF;
    dp[0] = 0;
    for (int i=1; i<=m; i++) {
        int t = dp[i-1] + tmp[i];
        dp[i] = (t > tmp[i]) ? t : tmp[i];
        sum = (dp[i] > sum) ? dp[i] : sum;
    }
    return sum;
}

int MaxSum2(int n, int m)
{
    int sum = -INF;
    int* tmp = new int[m+5]();
    for (int i=1; i<=n; i++)
    {
        memset(tmp, 0, sizeof(tmp));
        for (int j=i; j<=n; j++)
        {
            for (int k=1; k<=m; k++)
                tmp[k] += G[j][k];

            int maxn = MaxSum1(m, tmp, dp);
            cout << maxn << endl;
            
            sum = max(sum, maxn);
        }
    }
    delete[] tmp;
    return sum;
}

/*
5 5
-2 11  -4 13 -5
-2  2  42 10 -9
6   7 -15  6 20
-4  5   7 -1  6
10 -3  31  0 10

ans = 133
*/

int main()
{
    freopen("in.txt", "r", stdin);
    int n, m;
    while(cin >> n >> m && n && m)
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                cin >> G[i][j];
        int ans = MaxSum2(n, m);
        cout << ans << endl;
    }
    return 0;
}
