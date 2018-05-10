#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");

    int n, a, b, P = 0;
    vector<int> vt;

    fscanf(fi, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(fi, "%d %d", &a, &b);
        P += b;
        vt.push_back(a*b);
    }

    sort(vt.begin(), vt.end());

    float result = 0, tmp = 0;
    for (int i = 0; i < n; ++i) {
        tmp += 1.0 * vt[i] / P;
        result += tmp;
    }

    printf("%.4f\n", result);
    fprintf(fo, "%.4f\n", result);

    return 0;
}
