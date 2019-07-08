// https://www.luogu.org/problemnew/show/P2158
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MX 1000001

int n, k;

int euler_phi(int n) {
    int rest = n;
    for (int i = 2; i*i <= n; ++i) {    // O(sqrt(n))
        if (n % i == 0) {
            rest = rest / i * (i-1);    // 1 - 1 / p
            for (; n % i == 0; n /= i); // 把n中因子i除尽
        }
    }
    if (n != 1) rest = rest / n * (n-1); // phi(素数)=所有小于它的值
    return rest;
}

int main() {
//    freopen("in.txt", "r", stdin);
#if 1
    while (cin >> n) {
        if (n <= 1)
            cout << 0 << endl;
        else {
            int cnt = 0;
            for (int line = 2; line < n; ++line) {
                cnt += euler_phi(line);
            }
            cout << cnt * 2 + 3 << endl;
        }
    }
#else
    while (cin >> n) {
        cout << euler_phi(n) << endl;
    }
#endif // 1
    return 0;
}
