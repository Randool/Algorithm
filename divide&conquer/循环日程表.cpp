#include <cstdio>
#include <functional>
using namespace std;

#define MAXN 65

int table[MAXN][MAXN];

void copy_block(int x, int y, int sz, bool up) {
    int dx = x, dy = y + sz;

    if (up) dx -= sz;
    else dx += sz;

    for (int i = 0; i < sz; ++i)
        for (int j = 0; j < sz; ++j)
            table[dx+i][dy+j] = table[x+i][y+j];
}

void Schedule(int n) {
    for (int i = 0; i < n; ++i)
        table[i][0] = i+1;

    for (int sz = 1; sz != n; sz <<= 1) {
        for (int i = 0; i < n; i += sz*2) {
            copy_block(i, 0, sz, false);
            copy_block(i+sz, 0, sz, true);
        }
    }
}

void show(int n) {
    for (int i = 0; i < n; ++i) {
        printf("%2d | ", table[i][0]);
        for (int j = 1; j < n; ++j) {
            printf("%2d ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n & (n-1)) {
            printf("n != 2^k\n");
            continue;
        }
        Schedule(n);
        show(n);
    }

    return 0;
}
