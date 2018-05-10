#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 505
#define INF 0x3f3f3f3f

struct Edge {
    int from, to, dist;
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
struct Node {
    int dis, id;
    Node (int ID=0, int distant=0) : dis(distant), id(ID) {}
    bool operator < (const Node &rhs) const {
        return dis < rhs.dis;
    }
};

int dist[MAXN];
bool vis[MAXN];
vector<int> G[MAXN]; // ´æ±ßµÄ±àºÅ
vector<Edge> edges;


void dijkstra(int start, int n) {
    priority_queue<Node> Q;

    for (int i = 0; i < n; ++i) dist[i] = INF;
    dist[start] = 0;
    memset(vis, 0, sizeof(vis));

    Q.push(Node(start, 0));
    while (!Q.empty()) {
        Node cur = Q.top(); Q.pop();

        if (vis[cur.id]) continue;
        vis[cur.id] = true;

        for (int i = 0; i < G[cur.id].size(); ++i) {
            Edge &e = edges[G[cur.id][i]];
            if (dist[e.to] > dist[cur.id] + e.dist) {
                dist[e.to] = dist[cur.id] + e.dist;
                Q.push(Node(e.to, dist[e.to]));
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);

    int n, m, a, b, d;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &d);
        edges.push_back(Edge(a, b, d));
        G[a].push_back(edges.size()-1);
        edges.push_back(Edge(b, a, d));
        G[b].push_back(edges.size()-1);
    }

    dijkstra(0, n);

    for (int i = 0; i < n; ++i)
        printf("%d ", i); printf("\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", dist[i]);

    return 0;
}
