#include <cstdio>
using namespace std;

#define MAXN 505
#define show(x) printf("%d", x)
#define shown(x) printf("%d\n", x)

int d[MAXN];

int main() {
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");

    int n, k, t;

    fscanf(fi, "%d %d", &n, &k);
    for (int i = 1; i <= k+1; ++i) {
        fscanf(fi, "%d", &t);
        d[i] = d[i-1] + t;
    }

    int rest = n, count = 0;
    for (int i = 0; i <= k; ++i) {
        int next_dist = d[i+1] - d[i];
        if (next_dist <= rest) {
            rest -= next_dist;
        }
        else {
            rest = n - next_dist;
            ++count;
        }
    }

    printf("%d", count);
    fprintf(fo, "%d", count);

    return 0;
}
