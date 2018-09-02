// P1306 斐波那契公约数
#include <cstring>
#include <iostream>
#define MOD 100000000

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
    return (b ? gcd(b, a%b) : a);
}

struct Mat {
    LL mat[2][2];
    int h, w;
    Mat(int _h=2, int _w=2) {
        h = _h, w = _w;
        memset(mat, 0, sizeof(mat));
    }
};

Mat Multiply(const Mat &a, const Mat &b) {
    Mat ret(a.h, b.w);
    for (int i = 0; i < a.h; ++i)
    for (int j = 0; j < b.w; ++j)
    for (int k = 0; k < a.w; ++k) {
        LL tmp = a.mat[i][k] * b.mat[k][j] % MOD;
        ret.mat[i][j] = (ret.mat[i][j] + tmp) % MOD;
    }
    return ret;
}

int main() {
    LL n, m;
    cin >> n >> m;
    LL gcd_nm = gcd(n, m);
    if (gcd_nm <= 2) cout << 1 << endl;
    else {
        Mat raw(2, 1);
        raw.mat[0][0] = raw.mat[1][0] = 1;
        Mat f(2, 2);
        f.mat[0][0] = f.mat[0][1] = f.mat[1][0] = 1;
        gcd_nm -= 2;
        while (gcd_nm) {
            if (gcd_nm & 1)
                raw = Multiply(f, raw);
            f = Multiply(f, f);
            gcd_nm >>= 1;
        }
        cout << raw.mat[0][0] << endl;
    }
    return 0;
}
