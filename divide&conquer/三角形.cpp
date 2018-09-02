#include <cstdio>
using namespace std;

#define MAXN 2050

char G[MAXN][MAXN];


int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 1024; ++i)
    for (int j = 0; j < 2048; ++j) {
        G[i][j] = ' ';
    }

    G[0][0] = G[1][1] = '/';
    G[0][1] = G[0][2] = '_';
    G[0][3] = G[1][2] = '\\';

    int length = 4, half = 2, k = 1;
    while (k < n) {
        for (int i = 0; i < half; ++i)
        for (int j = 0; j < length; ++j)
            G[i][j+length] = G[i+half][j+half] = G[i][j];

        half <<= 1;
        length <<= 1;
        ++k;
    }

    for (int i = half-1; i >= 0; --i) {
        for (int j = 0; j < length; ++j)
            printf("%c", G[i][j]);
        printf("\n");
    }

    return 0;
}

/**
1
 /\
/__\4
/__\
 /\

2
   /\
  /__\
 /\  /\
/__\/__\8

3
       /\
      /__\
     /\  /\
    /__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\16
*/
