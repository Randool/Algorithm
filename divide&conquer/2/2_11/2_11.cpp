#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define LL long long
#define MAXN 100001

LL a[MAXN];

LL factors(LL n) {
    if (n < MAXN && a[n]) return a[n];
    LL cnt = (LL)1;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            cnt += factors((LL)n/i);
            if ((LL)i*i == n) break;
            cnt += factors((LL)i);
        }
    }
    if (n < MAXN) a[n] = cnt;
    return cnt;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    memset(a, 0, sizeof(a));
    LL n;
    cin >> n;
    cout << factors(n) << endl;

    return 0;
}
