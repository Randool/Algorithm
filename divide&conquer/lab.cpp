#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 40005

int n, cnt = 0;
int arr[MAXN];
int buff[MAXN];

void solve(int l, int r) {
    if (l == r) return;
    if (l+1 == r) {
        if (arr[l] > arr[r]) {
            int t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
            ++cnt;
        }
        return;
    }
    int mid = (l+r) >> 1;
    solve(l, mid);
    solve(mid+1, r);

    // merge sort
    for (int i = l; i <= r; ++i)
        buff[i] = arr[i];

    int i = l, p = l, q = mid+1, pre = 0;
    while (p <= mid && q <= r) {
        while (p <= mid && q <= r && buff[p] > buff[q]) {
            ++pre;
            arr[i++] = buff[q++];
        }
        cnt += pre;
        arr[i++] = buff[p++];
    }
    while (p <= mid) {
        arr[i++] = buff[p++];
        cnt += pre;
    }
    while (q <= r) {
        arr[i++] = buff[q++];
    }
}

void test(int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] > arr[j])
                ++ans;
        }
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    //test(n);
    solve(0, n-1);
    printf("%d", cnt);

    return 0;
}

/*
100
21 48 24 47 28 44 76 73 96 88 75 38 36 84 63 64 85 34 3 4 51 30 17 49 18 50 56 6 23 26 93 79 0 83 59 19 22 5 77 55 11 62 57 45 7 80 42 20 53 65 71 78 43 2 27 94 14 70 95 9 89 74 52 46 82 99 32 16 92 40 25 41 37 35 10 33 15 8 60 1 91 61 81 12 39 69 72 90 68 87 29 54 66 31 98 86 97 58 13 67
*/
