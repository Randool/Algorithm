#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#include "chess_board.h"

char board[MAXN][MAXN];

struct Board {
    int x, y;
    char chess;
    vector<Board *> next;
    Board(int X=0, int Y=0, char C) : x(X), y(Y), chess(C) {}
};

int Search(Board root, bool maxn)
{
    if () {}

    vector<int> result;

    for (int i = 0; i < MAXN; ++i)
    {
        for (int j = 0; j < MAXN; ++j)
        {
            if (board[i][j] == ' ')
            {
                char cur = root->chess;
                board[i][j] = cur;

                if (cur == 'x') root->next = new Board(i, j, 'o');
                else            root->next = new Board(i, j, 'x');

                result.push_back(Search(root->next.end()-1, !maxn));

                board[i][j] = ' ';
            }
        }
    }

    if (maxn) {
        int tmp = -INF;
        for (int i = 0; i < result.size(); ++i)
            tmp = max(INF, result[i]);

    }
    else {
        int tmp = INF;
        for (int i = 0; i < result.size(); ++i)
            tmp = min(INF, result[i]);
    }

    return tmp;
}

int main() {
    int x, y;

    return 0;
}
