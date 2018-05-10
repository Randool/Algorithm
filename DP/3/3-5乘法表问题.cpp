#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

#define MAXN 505
#define lt stMap[begin][k]
#define rt stMap[k+1][end]

struct State {
    int a, b, c;
    State() { a = b = c = 0; }
};
State stMap[MAXN][MAXN];

/**
a*a=b    a*b=b    a*c=a
b*a=c    b*b=b    b*c=a
c*a=a    c*b=c    c*c=c
*/

void show(int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            printf("%d %d %d, ", stMap[i][j].a, stMap[i][j].b, stMap[i][j].c);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // bbba
    // 0123
    string ss;
    cin >> ss;
    cout << ss << endl;
    int Len = ss.length();

    for (int i = 0; i < Len; ++i) {
        if (ss[i] == 'a') stMap[i][i].a = 1;
        else if (ss[i] == 'b') stMap[i][i].b = 1;
        else if (ss[i] == 'c') stMap[i][i].c = 1;
    }

    for (int len = 2; len <= Len; ++len) {
        for (int begin = 0; begin+len <= Len; ++begin) {
            int end = begin + len - 1;
            for (int k = begin; k <= end; ++k) {
                stMap[begin][end].a += lt.a * rt.c + lt.b * rt.c + lt.c * rt.a;
                stMap[begin][end].b += lt.a * rt.a + lt.a * rt.b + lt.b * rt.b;
                stMap[begin][end].c += lt.b * rt.a + lt.c * rt.b + lt.c * rt.c;
            }
        }
    }

    // show(Len);

    printf("%d\n", stMap[0][Len-1].a);

    return 0;
}
