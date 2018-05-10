#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
#define MAXN 1030
#define lowbit(x)	x&(-x)

int in, s;
int map[MAXN][MAXN];

void update(int x, int y, int t) {
    while (x < MAXN) {
        int yy = y;
        while (yy < MAXN) {
            map[x][yy] += t;
            yy += lowbit(yy);
        }
        x += lowbit(x);
    }
}

int getSum(int x, int y) {
    int s = 0;
    while (x) {
        int yy = y;
        while (yy) {
            s += map[x][yy];
            yy -= lowbit(yy);
        }
        x -= lowbit(x);
    }
    return s;
}

void Show(int N) {
    for (int i=0; i<=N; ++i) {
        for (int j=0; j<=N; ++j)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while (scanf("%d", &in))
    {
        if (in == 1)
        {
            int x, y, a;
            scanf("%d%d%d", &x, &y, &a);
            ++x, ++y;
            update(x, y, a);
            // Show(s);
        }
        else if (in == 2)
        {
            int l, b, r, t;
            scanf("%d%d%d%d", &l, &b, &r, &t);
            ++l, ++b, ++r, ++t;
            int ans = getSum(r,t)-getSum(l-1,t)-getSum(r,b-1)+getSum(l-1,b-1);
            printf("%d\n", ans);
        }
        else if (in == 0)
        {
            scanf("%d", &s);
            memset(map, 0, sizeof(map));
        }
        else if (in == 3) break;
    }

    return 0;
}
