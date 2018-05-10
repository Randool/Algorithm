#include <cstdio>
#include <iostream>
typedef long long LL;
using namespace std;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a%b);
}

void exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
    }
    else {
        exgcd(b, a%b, y, x);
        y -= x * (a/b);
    }
}
/*
77 51
10 44
34 79
*/
int main()
{
    //freopen("in.txt", "r", stdin);
    LL a, b, x, y;
    while (~scanf("%lld%lld", &a, &b)) {
        if (gcd(a, b) != 1) {
            puts("sorry");
            continue;
        }
        exgcd(a, b, x, y);

        // È·±£ x>0, y<0
        x %= b;
        if (x <= 0) x += b;
        y = (1-a*x) / b;

        printf("%lld %lld\n", x, y);
    }
    return 0;
}
