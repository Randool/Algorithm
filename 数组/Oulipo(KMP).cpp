// https://vjudge.net/problem/POJ-3461
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
#define MX 100001

int next[MX], t;
char W[MX], T[1000001];

void build_next(const char *W) {
    int i = 0, j = next[0] = -1, len = strlen(W);
    while (i <= len) {
        if (j < 0 || W[i] == W[j]) {
            ++i, ++j;
            next[i] = (W[i] != W[j]) ? j : next[j];
        }
        else j = next[j];
    }
}

int KMP(const char *W, const char *T) {
    int matched = 0;
    int len = strlen(T), top = strlen(W);
    build_next(W);
    int i = 0, j = 0;
    while (j != len) {
        if (i<0 || W[i] == T[j])
            ++i, ++j;
        else
            i = next[i];
        if (i == top) {
            ++matched;
            i = next[i];
        }
    }
    return matched;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", W, T);
        int result = KMP(W, T);
        printf("%d\n", result);
    }
    return 0;
}
