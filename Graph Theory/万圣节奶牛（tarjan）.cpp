#include <bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
#define MX 200001

int n, tic, min_loop = INF;
int next[MX];
int dfn[MX], low[MX];
stack<int> st;
bool in_stack[MX];

void tarjan(int x) {
    dfn[x] = low[x] = ++tic;    /// at least 1
    st.push(x);
    in_stack[x] = true;

    /// find child nodes. One here
    int v = next[x];
    if (v != -1) {
        if (!dfn[v]) {    // means have not been visited
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if (in_stack[v]) {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if (dfn[x] == low[x]) {
        // 一个loop
        int cnt = 0, tmp;
        do {
            tmp = st.top();
            st.pop();
            in_stack[tmp] = false;
            cnt += 1;
        } while (tmp != x);
        if (cnt == 1) {
            if (tmp == next[tmp])
                min_loop = 1;
        }
        else min_loop = min(min_loop, cnt);
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    memset(next, -1, sizeof(next));

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &next[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    printf("%d\n", min_loop);

    return 0;
}
