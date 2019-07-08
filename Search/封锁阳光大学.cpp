// https://www.luogu.org/problemnew/show/P1330
#include <bits/stdc++.h>
using namespace std;
#define MX 200001

typedef vector<int>::iterator Iter;
typedef pair<int, bool> pib;

int n, m, a, b, ans;
int read();
vector<int> G[MX];
bool px[MX];
bool vis[MX];
bool glob_vis[MX];  // 用于记录是否全局访问

int bfs(int start, bool put) {
    int cnt = 0;
    int nodes_cnt = 0;  // 这样就只需要遍历一遍
    queue<pair<int, bool> > Q;
    Q.push(make_pair(start, put));

    while (!Q.empty()) {
        int cur = Q.front().first;
        bool put_ = Q.front().second;
        Q.pop();

//        cout << cur << " ";
        vis[cur] = 1;
        nodes_cnt += 1;
        if (put_) px[cur] = 1, ++cnt;

        for (Iter i = G[cur].begin(); i != G[cur].end(); ++i) {
            if (vis[*i]) {
                if (px[*i] == put_) {
//                    cout << endl;
                    return -1;
                }
            }
            else {
                Q.push(make_pair(*i, !put_));
            }
        }
    }
//    cout << " +" << min(cnt, nodes_cnt - cnt) << endl;
    return min(cnt, nodes_cnt - cnt);
}

void judge() {
    int cnt = 0, tmp = 0;
    memset(px, 0, sizeof(px));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if ((tmp = bfs(i, true)) == -1) {
                puts("Impossible");
                return;
            }
            cnt += tmp;
        }
    }
    printf("%d\n", cnt);
}

int main() {
//    freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 1; i <= m; ++i) {
            a = read();
            b = read();
            G[a].push_back(b);
            G[b].push_back(a);
        }
        judge();
    }

    return 0;
}

int read() {
    int x = 0, p = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') p |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch-'0', ch = getchar();
    return p ? -x : x;
}

/*
3 3
1 2
1 3
2 3

3 2
1 2
2 3

30 12
18 12
11 5
5 30
15 23
28 2
12 2
3 26
7 28
25 22
4 3
27 22
6 9
*/
