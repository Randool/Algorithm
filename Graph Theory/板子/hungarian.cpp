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
vector<int> G[max_nodes];   //��������
typedef vector<int>::iterator iterator_t;

int num_nodes, num_edges;
int num_left, num_right;

int matching[max_nodes]; // ������
bool check[max_nodes];

bool dfs(int u) {
    for (iterator_t i = G[i].begin(); i != G[i].end(); ++i) {
        int v = edges[*i].to;
        // Ҫ���ڽ���·�� �� �����δ���ǵ㣬˵������·������·
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
    return false;   //����������·
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
