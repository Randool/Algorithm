#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 55

int found, n, c, cursize, rest, S[MAXN];
vector<int> subset;

void find_subset(int cur) {
    if (found || cur == n) return;
    int tmp = S[cur];
    // 放
    rest -= tmp;
    subset.push_back(tmp);
    cursize += tmp;
    if (cursize == c) {
        found = 1;
        int len = subset.size();
        for (int i = 0; i < len; ++i)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    if (cursize < c)
        find_subset(cur+1);

    // 不放；取出，最后放回rest中
    cursize -= tmp;
    subset.pop_back();
    if (!fol,ound && cursize + rest >= c)
        find_subset(cur+1);
    rest += tmp;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
    scanf("%d %d", &n, &c);

    cursize = rest = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
        rest += S[i];
    }

    find_subset(0);
    if (!found) printf("No Solution!");

    return 0;
}
