#include <cstdio>
using namespace std;

typedef unsigned int uint;

void solve(uint n) {
    uint mask = 0x80000000;
    bool first = 1;
    for (int i = 31; i >= 0; --i) {
        if (n & mask) {
            if (first)  first = 0;
            else printf("+");

            if (i == 0)
                printf("2(0)");
            else if (i == 1)
                printf("2");
            else {
                printf("2(");
                solve(i);
                printf(")");
            }
        }
        mask >>= 1;
    }
}

int main() {
    uint n;
    while (~scanf("%u", &n)) {
        solve(n);
        printf("\n");
    }
    return 0;
}

/**
max 4294967295 = 0x80000000
1315
10100100011
2^10 + 2^8 + 2^5 + 2 + 1
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
*/
