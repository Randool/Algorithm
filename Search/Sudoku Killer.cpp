#include <cstring>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int Map[10][10];
int pos[100];
int nullNum = 0;

bool scanf_graph() {
    nullNum = 0;
    char buf[20];
    for (int i = 0; i < 9; ++i) {
        gets(buf);
        if (strlen(buf) <= 10) return false;
        for (int j = 0; j < 9; ++j) {
            Map[i][j] = buf[j<<1] - '0';
            if (buf[j<<1] == '?')
                pos[nullNum++] = i*9 + j, Map[i][j] = 0;
        }
    }
    return true;
}

void print_l() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 8; ++j)
            printf("%d ", Map[i][j]);
        printf("%d\n", Map[i][8]);
    }
}

bool canput(int x, int y, int c) {
    for (int i = 0; i < 9; ++i) {
        if (Map[x][i] == c || Map[i][y] == c) return false;
    }
    int _x = (x/3)*3, _y = (y/3)*3;
    for (int i = _x; i < _x+3; ++i)
        for (int j = _y; j < _y+3; ++j)
            if (Map[i][j] == c) return false;
    return true;
}

void DFS(int n) {
    if (n == nullNum) {
        print_l();
        return;
    }
    int x = pos[n] / 9;
    int y = pos[n] % 9;
    for (int i = 1; i <= 9; ++i) {
        if (canput(x, y, i)) {
            Map[x][y] = i;
            DFS(n+1);
            Map[x][y] = 0;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int stratch = 0;
    while (scanf_graph()) {
        if (stratch++) puts("");
        DFS(0);
    }
    return 0;
}
