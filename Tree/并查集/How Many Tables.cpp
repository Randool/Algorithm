// http://acm.hdu.edu.cn/showproblem.php?pid=1213
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1005
using namespace std;

int fri[MAXN];
bool temp[MAXN];
int T, n, m, a, b;

void Init(int n) {
    for (int i=1; i<=n; ++i) fri[i] = i, temp[i] = 0;
}

int Find(int n) {
    if (fri[n] == n) return n;
    return fri[n] = Find(fri[n]);
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        Init(n);

        for (int i=0; i<m; ++i)
        {
            scanf("%d%d", &a, &b);
            int x = Find(a);
            int y = Find(b);
            if (x != y)
            {
                fri[x] = y;
            }
        }

        for (int i=1; i<=n; ++i) // Â·¾¶Ñ¹Ëõ
            Find(i);

        int same = 0;
        for (int i=1; i<=n; ++i)
        {
            if (temp[Find(i)])
                ++same;
            temp[Find(i)] = 1;
        }

        printf("%d\n", n-same);
    }
    return 0;
}
