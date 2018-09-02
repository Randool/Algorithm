#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 1010
#define INF 0x3f3f3f3f

int step[MAXN], n, m;

struct Node {
    int to, flow;
    int rev; // 记录反向边 rev 的 index
    Node (int to=0, int flow=0, int rev=0) : to(to), flow(flow), rev(rev) {}
};

vector<Node> graph[MAXN];

void addEdge(int from, int to, int val) {
    graph[from].push_back(Node(to, flow, graph[to].size()));    // 为什么用size
    graph[to].push_back(Node(from, 0, graph[from].size()-1));
}

bool BFS(int st, int ed) {
    memset(step, -1, sizeof(step));
    queue<int> Q;
    Q.push(st);
    step[st] = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < graph[cur].size(); ++i) {
            Node &tmp = graph[cur][i];
            if (step[tmp.to] == -1 && tmp.flow > 0) {
                step[tmp.to] = step[cur] + 1;
                if (tmp.to == ed) return true;
                Q.push(tmp.to);
            }
        }
    }
    return step[ed] != -1;
}

int DFS(int st, int ed, int flow) {
}

int Dinic(int st, int ed) {}

int main() {
    int a, b, val;
    while (~scanf("%d %d", &m, &n)) {
        memset(head, -1, sizeof(head));
        cnt = 0;
        while (m--) {
            scanf("%d %d %d", &a, &b, &val);
            addEdge(a, b, val);
        }
        printf("%d\n", Dinic(1, n));
    }

    return 0;
}
