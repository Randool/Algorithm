#include <cstdio>
using namespace std;

#define showd(x) printf("%d\n", x)

#define MAXN 505

int fac[MAXN], idx=0;

int optimal(int n) {
    if (n <= 4) return n;

    int ans = 1, i;
    fac[idx] = 2;   // 第一个数是2
    n -= 2;         // 从2开始分解

    // 不断分解出连续的自然数
    while (n > fac[idx]) {
        fac[idx + 1] = fac[idx] + 1;
        n -= fac[++idx];
    }

    // 如果剩余的数正好等于最大数，就先给最大数加1
    if (n == fac[idx]) {
        ++fac[idx];
        --n;
    }
    // 均摊剩余的1，并做乘法
    for (i = idx; i > idx - n; --i) ans *= ++fac[i];
    for (i; i >= 0; --i) ans *= fac[i];

    return ans;
}

int main() {
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");

    int n, result;
    fscanf(fi, "%d", &n);

    showd(result = optimal(n));
    fprintf(fo, "%d\n", result);

    return 0;
}
