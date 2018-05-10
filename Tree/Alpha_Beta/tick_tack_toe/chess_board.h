#define MAXN 3
#define INF 0x3f3f3f3f

int Win(char board[][MAXN]) {
    for (int i = 0; i < MAXN; ++i) {
        if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x') return 1;
        if (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o') return 2;
    }
    for (int j = 0; j < MAXN; ++j) {
        if (board[0][j] == 'x' && board[1][j] == 'x' && board[2][j] == 'x') return 1;
        if (board[0][j] == 'o' && board[1][j] == 'o' && board[2][j] == 'o') return 2;
    }
    if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') return 1;
    if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') return 2;
}

void initial_board(char board[][MAXN]) {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            board[i][j] = ' ';
        }
    }
}

void get_board(char board[][MAXN]) {
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            scanf("%c", &board[i][j]);
}

void show_board(char board[][MAXN]) {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}
