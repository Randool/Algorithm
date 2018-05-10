#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define maxn 100005
#define max_nodes 5005
#define INF 0x3f3f3f3f

struct Edge {
    int from, to, weight;
    Edge() {}
    Edge(int a, int b, int c) : from(a), to(b), weight(c) {}
};
vector<Edge> edges;
vector<int> G[max_nodes];   //储存边序号
typedef vector<int>::iterator iterator_t;

int num_nodes, num_edges;
int num_left, num_right;

int matching[max_nodes]; // 储存结果
bool check[max_nodes];

bool dfs(int u) {
    for (iterator_t i = G[i].begin(); i != G[i].end(); ++i) {
        int v = edges[*i].to;
        // 要求不在交替路中 且 如果是未覆盖点，说明交替路是增广路
        if (check[v])
        {
            check[v] = true;
            if (matching[v] == -1 || dfs(matching[v])) {
                matching[u] = v;
                matching[v] = u;
                return true;
            }
        }
    }
    return false;   //不存在增广路
}

int hungarian() {
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u = 0; u < num_left; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u)) ++ ans;
        }
    }
    return ans;
}

int main() {

    return 0;
}
