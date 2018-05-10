#include <iostream>
#include <cstring>
#define N 50005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;

LL a[N], dp[N];

LL MaxSum1(int n, LL* a, LL* dp)
{
    LL sum = -9999999;
    for (int i=1; i<=n; i++) {
        LL tmp = dp[i-1] + a[i];
        dp[i] = (tmp > a[i]) ? tmp : a[i];
        sum = (sum < dp[i]) ? dp[i] : sum;
    }
    return sum;
}

int main()
{
    int n;
	while(cin >> n && n)
    {
		LL maxn = -INF;
		for (int i=1; i<=n; i++) dp[i] = a[i] = 0;
		for (int i=1; i<=n; i++)
            cin >> a[i];
        maxn = MaxSum1(n, a, dp);
		cout << maxn << endl;
	}
	return 0;
}
