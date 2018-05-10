#include <cstdio>
#include <iostream>
typedef long long LL;
using namespace std;

LL P, m, n;
LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a%b); }

int main()
{
	freopen("in.txt", "r", stdin);
    scanf("%lld", &P);
    while (P--)
    {
        scanf("%lld%lld", &m, &n);
        if (m % n == 0) {
            puts("YES");
            continue;
        }
        LL _gcd = gcd(m, n);
        // cout << _gcd << endl;
        if (_gcd == m || _gcd == n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
