#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 5050

int p[MAXN];
int s[MAXN];
int l[MAXN];
int b[MAXN];

int length(int i) {
    int k = 1;
    i >>= 1;
    while (i > 0) {
        i >>= 1;
        ++k;
    }
    return k;
}

void Compress(int n, int p[], int s[], int l[], int b[]) {
    const int maxL = 256, header = 11;
    for (int i = 0; i < n; ++i) {
        b[i] = length(p[i]);
        int bmax = b[i];
        s[i] = s[i-1] + bmax;
        l[i] = 1;
        for (int j = 2; j <= i && j <= maxL; ++j) {
            bmax = max(bmax, b[i-j+1]);
            if (s[i] > s[i-1] + j*bmax) {
                s[i] = s[i-j] + j*bmax;
                l[i] = j;
            }
        }
        s[i] += header;
    }
}

int main() {
    int n;

    return 0;
}
