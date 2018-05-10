#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 105

int G[MAXN][MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &G[i][j]);
        }
    }
    for (int i = n-1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            G[i][j] += max(G[i+1][j], G[i+1][j+1]);
        }
    }
    printf("%d\n", G[1][1]);
    return 0;
}
