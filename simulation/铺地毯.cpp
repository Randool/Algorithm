#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

struct Carpet {
    int x1, y1, x2, y2;
    bool inCap(int x, int y) const {
        return (x<=x2 && x>=x1 && y<=y2 && y>=y1);
    }
} carpet[MAXN];

int main() {
    //freopen("carpet.in", "r", stdin);
    //freopen("carpet.out", "r", stdout);

    int n, a, b, c, d, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a,&b,&c,&d);
        carpet[i].x1 = a, carpet[i].y1 = b;
        carpet[i].x2 = a + c, carpet[i].y2 = b + d;
    }
    scanf("%d%d", &x, &y);
    for (int i = n-1; i >= 0; --i) {
        if (carpet[i].inCap(x, y)) {
            printf("%d", i+1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
