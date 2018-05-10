// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1009
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

LL dp(LL n) {
    LL count = 0, i = 1, current = 0, after = 0, before = 0;
    while (n / i) {
        before = n / (i * 10);
        current = (n / i) % 10;
        after = n - (n / i) * i;
        if (current > 1)
            count += (before + 1) * i;
        else if (current == 0)
            count += before * i;
        else if (current == 1)
            count += before * i + after + 1;
        i *= 10;
    }
    return count;
}

int main() {
    LL n;
    scanf("%lld", &n);
    printf("%lld\n", dp(n));
    return 0;
}
