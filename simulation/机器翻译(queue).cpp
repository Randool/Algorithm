#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define sf(t) scanf("%d", &t)
#define pf(t) printf("%d", t)
#define sff(a, b) scanf("%d%d", &a, &b)
/**
3 7
1 2 1 5 4 4 1
*/
bool inq[MAXN];
queue<int> Q;

int main() {
    int m, n, t, cnt = 0;
    sff(m, n);

    memset(inq, 0, sizeof(inq));
    while (!Q.empty()) Q.pop();

    for (int i = 0; i < n; ++i) {
        sf(t);
        if (!inq[t]) {
            inq[t] = 1;
            if (Q.size() < m) {
                Q.push(t);
                ++cnt;
            }
            else {
                int tmp = Q.front();
                inq[tmp] = 0;
                Q.pop();
                Q.push(t);
                ++cnt;
            }
        }
    }
    pf(cnt);
    return 0;
}
