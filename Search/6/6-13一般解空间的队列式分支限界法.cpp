#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 55
#define abs(a) (a >= 0 ? a : -a)
#define Pop(Q, a) (a = Q.top(), Q.pop())

int n, m, k, x, y;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool G[MAXN][MAXN];

class Path {
public:
    int x, y;   // 当前坐标
    int dist;   // 离终点的距离
    int cnt;    // 记录步长
    queue<pair<int, int> > path;   // 路径

    Path(int X=0, int Y=0) : x(X), y(Y), cnt(0) {
        path.push(make_pair(X, Y));
    }

    friend operator < (const Path &a, const Path &b) {
        if (a.cnt == b.cnt)
            return a.dist > b.dist;
        else return a.cnt > b.cnt;
    }
};

#define XinG(x) ((x >= 0) && (x < n))
#define YinG(y) ((y >= 0) && (y < m))
#define canGo(x, y) ((G[x][y] != 1) && XinG(x) && YinG(y))
#define arrive(tX, tY, path) (path.x == tX && path.y == tY)

void go_to_target() {

    int tX, tY, got = 0;
    scanf("%d %d %d %d", &x, &y, &tX, &tY);

    Path cur(x, y), next;

    priority_queue<Path> pq;
    cur.dist = abs(tX - x) + abs(tY - y);
    pq.push(Path(x, y));

    while (!pq.empty()) {
        Pop(pq, cur);
        if (arrive(tX, tY, cur)) {
            got = 1;
            break;
        }
        G[cur.x][cur.y] = 1;
        for (int i = 0; i < 4; ++i) {
            next = cur;
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (canGo(nx, ny)) {
                next.cnt += 1;
                next.x = nx;
                next.y = ny;
                next.dist = abs(tX - nx) + abs(tY - ny);
                next.path.push(make_pair(nx, ny));
                pq.push(next);
            }
        }
    }

    if (!got) {
        printf("No Solution!\n");
        return;
    }

    // 到达终点
    printf("%d\n", cur.cnt);
    while (!cur.path.empty()) {
        pair<int, int> xy = cur.path.front();
        cur.path.pop();
        printf("%d %d\n", xy.first, xy.second);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &x, &y);
        G[x][y] = 1;
    }
    go_to_target();

    return 0;
}
