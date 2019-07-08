#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 1010;
const int INF = 0x7fffffff;

struct Node {
    int to;
    int next;
    int c;  // 流量
} Edge[MAXN*2]; //因为要建立反向边,所以边的数目要为两倍

int head[MAXN];
int step[MAXN];
int cnt;

void addEdge(int u, int v, int val) {
    Edge[cnt].to = v;
    Edge[cnt].next = head[u];
    Edge[cnt].c = val;
    head[u] = cnt++;

    Edge[cnt].to = u;
    Edge[cnt].c = 0;
    Edge[cnt].next = head[v];
    head[v] = cnt++;
}

bool BFS(int st, int ed) {
    queue<int> que;
    que.push(st);
    memset(step, -1, sizeof(step));
    step[st] = 0;

    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int i = head[u]; i != -1; i = Edge[i].next) {
            int v = Edge[i].to;
            if(step[v] == -1 && Edge[i].c > 0) {
                step[v] = step[u]+1;
                que.push(v);
                if(v == ed) return true;
            }
        }
    }
    return step[ed] != -1;
}

int DFS(int st, int ed, int flow) {
    if(st == ed || !flow) return flow;
    int curr = 0;
    for(int i = head[st]; i != -1; i = Edge[i].next) {
        if(step[st] + 1 == step[Edge[i].to] && Edge[i].c > 0) {
            int d = DFS(Edge[i].to, ed, min(Edge[i].c, flow));
            if(d > 0) {
                Edge[i].c -= d;
                Edge[i^1].c += d;   // 添反向边的时候是相邻的,i^1取相邻数;
                curr += d;          // 累加当前节点的某条路径的合适流量
                flow -= d;          // 当前节点的容量减去某条路径的合适流量
                if(!flow) break;    // 如果当前节点的容量用完,说明无法再通过任何流量
            }
        }
    }
    if(curr == 0)
        step[st] = INF;   // 如果当前节点无任何流量通过,取消标记
    return curr;
}

int Dinic(int st, int ed) {
    int flow = 0;
    while(BFS(st, ed)) {
        flow += DFS(st, ed, INF);
    }
    return flow;
}

int main() {
    int n, m, a, b, val;
    while(scanf("%d%d", &m, &n) != EOF) {
        memset(head, -1, sizeof(head));
        cnt = 0;
        while(m--) {
            scanf("%d%d%d", &a, &b, &val);
            addEdge(a, b, val);
        }
        printf("%d\n", Dinic(1, n));
    }
}
