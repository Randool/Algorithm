// https://www.luogu.org/problemnew/show/P1316
#include <cstdio>
#include <algorithm>
using namespace std;
#define MX 100001

int A, B;
int x[MX];

int judge(int a) {
    int idx = 1, cnt = 1;
    for (int i = 2; i <= A; ++i) {
        if (x[i] - x[idx] >= a) {
            cnt += 1;
            idx = i;
        }
    }
    if (cnt >= B) return 1;
    return 0;
}

int main() {
    scanf("%d%d", &A, &B);
    for (int i = 1; i <= A; ++i) {
        scanf("%d", &x[i]);
    }
    sort(x+1, x+1+A);
    int low = 1, high = x[A]-x[1];
    while (low < high) {
        int mid = (low + high + 1) >> 1;
        if (judge(mid)) low = mid;
        else high = mid - 1;
    }
    printf("%d\n", low);
    return 0;
}
/*
5 3
1 2 3 4 5
-----
2
*/
