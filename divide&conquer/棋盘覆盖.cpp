#include <cstdio>
#include <cstring>
#include <functional>
using namespace std;

#define MAXN 50

int board[MAXN][MAXN], tile;

void showBoard(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            printf("%3d", board[i][j]);
        printf("\n");
    }
}

/**
 * @@ x: 左上角行号
 * @@ x: 左上角列号
 * @@ bx: 特殊块行号
 * @@ by: 特殊块列号
 */
void CoverBoard(int size, int x, int y, int bx, int by) {
    if (size == 1) return;

    int semi = size >> 1;
    int mx = x + semi;
    int my = y + semi;
    int t = ++tile;

    // 左上角
    if (bx < mx && by < my) // 特殊块在该矩阵中
        CoverBoard(semi, x, y, bx, by);
    else {
        board[mx-1][my-1] = t;
        CoverBoard(semi, x, y, mx-1, my-1);
    }

    // 右上角
    if (bx < mx && by >= my)
        CoverBoard(semi, x, my, bx, by);
    else {
        board[mx-1][my] = t;
        CoverBoard(semi, x, my, mx-1, my);
    }

    // 左下角
    if (bx >= mx && by < my)
        CoverBoard(semi, mx, y, bx, by);
    else {
        board[mx][my-1] = t;
        CoverBoard(semi, mx, y, mx, my-1);
    }

    // 右下角
    if (bx >= mx && by >= my)
        CoverBoard(semi, mx, my, bx, by);
    else {
        board[mx][my] = t;
        CoverBoard(semi, mx, my, mx, my);
    }
}

int main() {
    int size, x, y;
    while (~scanf("%d %d %d", &size, &x, &y)) {
        if ((size & (size-1))) {
            printf("Size != 2^k\n");
            continue;
        }
        tile = 0;
        memset(board, 0, sizeof(board));
        board[x][y] = -1;
        //showBoard(size);
        CoverBoard(size, 0, 0, x, y);
        showBoard(size);
    }
    return 0;
}
