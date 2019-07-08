#include <cstdio>
#include <algorithm>
using namespace std;
#define MX 1000001

int n, m, l, r;
bool no_prime[MX];
int pri[MX];

void Sieve() {
    no_prime[1] = 1;
    for (int i = 2; i <= m; ++i) {
        if (no_prime[i]) continue;
        for (int j = i + i; j <= m; j += i)
            no_prime[j] = 1;
    }
    int cnt = 0;
    for (int i = 2; i <= m; ++i) {
        // 计算前缀和
        if (!no_prime[i]) ++cnt;
        pri[i] = cnt;
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    Sieve();    // 筛法
    while (n--) {
        scanf("%d%d", &l, &r);
        if (l < 1 || l > m || r < 1 || r > m) {
            puts("Crossing the line");
            continue;
        }
        printf("%d\n", pri[r] - pri[l-1]);
    }
    return 0;
}
/*
2 5
1 3
2 6
-----
2
Crossing the line
*/
