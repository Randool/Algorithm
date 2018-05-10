// https://www.luogu.org/problemnew/show/3371
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
#define INF 2147483647
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d%d", &a, &b)
#define sfff(a, b, c) scanf("%d%d%d", &a, &b, &c)

struct Edge {
    int from, to, weight;
    Edge (int f=0, int t=0, int w=0) {
        from = f, to = t, weight = w;
    }
};
typedef pair<int, int> Node; //first distance, second node

vector<Edge> edges;
vector<int> G[MAXN];
int dist[MAXN];
bool vis[MAXN];

void Dijkstra(int start, int n) {
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    /// Init
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= n; ++i) dist[i] = INF;
    dist[start] = 0;

    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        int id = cur.second, d = cur.first;

        if (vis[id]) continue;
        vis[id] = true;

        for (int i = 0; i < G[id].size(); ++i) {
            Edge &e = edges[G[id][i]];
            if (dist[e.to] > dist[id] + e.weight) {
                dist[e.to] = dist[id] + e.weight;
                pq.push(make_pair(dist[e.to], e.to));
            }
        }
    }
}

int main() {
    int n, m, s, f, g, w;
    sfff(n, m, s);
    for (int i = 0; i < m; ++i) {
        sfff(f, g, w);
        G[f].push_back(edges.size());
        edges.push_back(Edge(f, g, w));
    }
    Dijkstra(s, n);
    for (int i = 1; i <= n; ++i)
        printf("%d ", dist[i]);

    return 0;
}
/*
4 6 1
2 1 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
*/
