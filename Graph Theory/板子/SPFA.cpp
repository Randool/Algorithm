#include <bits/stdc++.h>
using namespace std;
#define max_nodes 5005
#define INF 0x3f3f3f3f

int num_nodes, num_edges;

struct Edge {
    int from, to, weight;
    Edge (int f, int t, int w) : from(f), to(t), weight(w) {}
};
vector<Edge> edges;
vector<int> G[max_nodes];
int p[max_nodes];
int d[max_nodes];

/**************/
bool in_queue[max_nodes];
int cnt[max_nodes];

bool SPFA(int s) {
    int u;
    queue<int> Q;
    memset(in_queue, 0, sizeof(in_queue));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < num_nodes; ++i) d[i] = INF;
    d[s] = 0;
    Q.push(s), in_queue[s] = true;
    while (!Q.empty())
    {
        in_queue[u = Q.front()] = false, Q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge &e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.weight) {
                d[e.to] = d[u] + e.weight;
                p[e.to] = G[u][i];
                if (!in_queue[e.to]) {
                    Q.push(e.to), in_queue[e.to] = true;
                    if (++cnt[e.to] > num_nodes) return false;  // ÅÐ¸º»·
                }
            }
        }
    }
    return true;
}

int main()
{


    return 0;
}
