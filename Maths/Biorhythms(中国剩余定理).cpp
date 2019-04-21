#include <cstdio>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (b==0) {
        x = 1, y = 0;
        return a;
    } else {
        int gcd = exgcd(b, a%b, y, x);
        y -= a/b * x;
        return gcd;
    }
}

// 求a关于m的乘法逆元
int mod_inverse(int a, int m) {
    int x, y;
    if (exgcd(a,m,x,y)==1) // a * x + m * y = 1
        return (x % m + m) % m;
    return -1;
}

int main() {
    // 23, 28, and 33
    int p, e, i, d, Case = 0, x, y;
    int m1 = 28*33, m2 = 23*33, m3 = 23*28, m = 23*28*33;
    int m1_ = mod_inverse(m1, 23);
    int m2_ = mod_inverse(m2, 28);
    int m3_ = mod_inverse(m3, 33);

    scanf("%d", &p);
    while (scanf("%d%d%d%d", &p, &e, &i, &d)) {
        if (p == -1 && e == -1 && i == -1 && d == -1)
            break;
        int ans = (m1*m1_*p + m2*m2_*e + m3*m3_*i - d + 21252) % 21252;
        if (!ans)
            ans = 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", ++Case, ans);
    }
    return 0;
}
