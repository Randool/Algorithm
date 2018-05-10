#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1005
using namespace std;

int f[MAXN], m[8][8];

int main()
{
    int a, b, c, x, y, k;
    while (~scanf("%d%d%d", &a, &b, &c)) {
        memset(m, 0, sizeof(m));
        f[1] = f[2] = x = y = 1;
        k = 3;
        while (!m[x][y])
        {
            m[x][y] = k;
            f[k] = y = (a*y+b*x) % 7;
            x = f[k-1];
            ++k;
        }
        int pre = m[x][y];
        int h = m[x][y];
        int len = c - h;
        if (c < k) printf("%d\n", f[c]);
        else printf("%d\n", f[h+len%(k-h)]);
        else printf("%d\n", f[(c-h)%(k-h)+h]);
    }
    return 0;
}
