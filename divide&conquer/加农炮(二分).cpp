#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;

int A[MAXN], B[MAXN];
int hmax = 0, t, pos;

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    for (int i=0; i<m; ++i) {
        scanf("%d", &A[i]);
        B[i] = hmax = max(hmax, A[i]);
    }

    for (int i=0; i<n; ++i) {
        scanf("%d", &t);
        if (t <= A[0] || t > hmax) continue;
        pos = lower_bound(B, B+m, t) - B;
        A[pos-1] += 1;
        B[pos-1] = max(B[pos-1], A[pos-1]);
    }

    for (int i=0; i<m; ++i)
        printf("%d\n", A[i]);

    return 0;
}
/*
9 11
1 2 0 4 3 2 1 5 7
2 8 0 7 6 5 3 4 5 6 5
*/
