#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define N 1005
#define MAXN 10005
#define lowbit(x) x&(-x)

int d[MAXN];

void update(int x, int num) {
    while (x < N) {
        d[x] += num;
        x += lowbit(x);
    }
}

int getSum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += d[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    int n, a, b;

    FILE *fi = fopen("input.txt", "r");
    fscanf(fi, "%d", &n);

    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        fscanf(fi, "%d %d", &a, &b);
        vec.push_back(a);
        vec.push_back(b);
        update(a, 1);
        update(b+1, -1);
    }

    int sum = 0;
    for (int i = 0; i < vec.size(); ++i)
        sum = max(sum, getSum(vec[i]));

    printf("%d\n", sum);

    FILE *fo = fopen("output.txt", "w");
    fprintf(fo, "%d", sum);

    return 0;
}
