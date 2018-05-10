#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 1005

bool vis[2*MAXN];
int G[2][MAXN];

void show(int n) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= n; ++j)
            printf("%d ", G[i][j]);
        printf("\n");
    }
    printf("\n");
}

void easy_tab(const int cur, const int total, int &cnt) {
    if (cur == total+1) {
        //show(total/2);
        ++cnt;
        return;
    }
    for (int i = 1; i <= total; ++i) {
        if (vis[i]) continue;   // ¶óÉ±

        if (cur <= total / 2) { // G[0][x]
            if (i > G[0][cur-1]) {
                G[0][cur] = i;
                vis[i] = true;
                easy_tab(cur+1, total, cnt);
                vis[i] = false;
            }
        }
        else {  // G[1][x]
            if (cur == total/2+1) {
                if (i > G[0][1]) {
                    G[1][1] = i;
                    vis[i] = true;
                    easy_tab(cur+1, total, cnt);
                    vis[i] = false;
                }
            }
            else {
                if (i > G[0][cur-total/2] && i > G[1][cur-total/2-1]) {
                    G[1][cur-total/2] = i;
                    vis[i] = true;
                    easy_tab(cur+1, total, cnt);
                    vis[i] = false;
                }
            }
        }
    }
}

int tab(int n) {
    if (n == 0 || n == 1) return 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += tab(i) * tab(n-i-1);
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, cnt = 0;
    cin >> n;

    memset(vis, 0, sizeof(vis));

    //easy_tab(1, n*2, cnt);
    //cout << cnt << endl;

    cout << tab(n) << endl;

    return 0;
}
