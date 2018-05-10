// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=2006
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define max_nodes 5005
#define INF 0x3f3f3f3f

int m, n, a, b;
int matching[max_nodes];
bool check[max_nodes];
struct Edge {
    int from, to;
    Edge() {}
    Edge(int f, int t) : from(f), to(t) {}
};
vector<Edge> edges;
vector<int> G[max_nodes]; //储存边序号
typedef vector<int>::iterator iterator_t;

bool dfs(int u) {
    for (iterator_t i = G[u].begin(); i != G[u].end(); ++i) {
        int v = edges[*i].to;
        if (!check[v]) { // 不在交替路中
            check[v] = true;
            if (matching[v] == -1 || dfs(matching[v])) {
                matching[u] = v;
                matching[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    int result = 0;
    memset(matching, -1, sizeof(matching));
    for (int u = 1; u <= m; ++u) {
        if (matching[u] == -1) {
            memset(check, 0 ,sizeof(check));
            if (dfs(u)) ++result;
        }
    }
    return result;
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &m, &n);
    while (~scanf("%d%d", &a, &b)) {
        if (a < 0|| b < 0) break;
        G[a].push_back(edges.size());
        edges.push_back(Edge(a, b));
        G[b].push_back(edges.size());
        edges.push_back(Edge(b, a));
    }
    int result = hungarian();
    if (!result) puts("No Solution!");
    else printf("%d\n", result);
    return 0;
}
