#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAXN 55

int n, m;
int Map[MAXN][MAXN];
int dx[] = {-2, -1, 1, 2, -2, -1,  1,  2};
int dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};

inline bool canGo(int x, int y) {
    return (x>=0) && (x<n) && (y>=0) && (y<m) && !Map[x][y];
}
inline void show(int Map[][MAXN]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%3d", Map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

inline float dist(const Node &node) {
    return pow(node.nx-n, 2)* pow(node.nx-n, 2);
}

struct Node {
    int nx, ny;
    Node(int x, int y) : nx(x), ny(y) {}
    friend bool operator < (const Node &a, const Node &b) {
        return dist(a) > dist(b);
    }
};

bool horse(int x, int y, int cnt) {
    Map[x][y] = cnt;
    bool flag = false;
    Map[x][y] = cnt;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (cnt == n*m && !nx && !ny) {
            show(Map);
            return true;
        }
        if (canGo(nx, ny)) {
            flag = horse(nx, ny, 1+cnt);
            if (flag)
                return true;
        }
    }
    if (!flag) {
        Map[x][y] = 0;
        return false;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    horse(0, 0, 1);

    return 0;
}
