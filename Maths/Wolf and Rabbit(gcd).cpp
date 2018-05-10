// https://cn.vjudge.net/contest/171431#problem/J
#include <cstdio>
#include <iostream>
typedef long long LL;
using namespace std;

LL P, m, n;
LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a%b); }

int main()
{
    scanf("%lld", &P);
    while (P--) {
        scanf("%lld%lld", &m, &n);
        LL _gcd = gcd(m, n);
        if (_gcd == 1)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
