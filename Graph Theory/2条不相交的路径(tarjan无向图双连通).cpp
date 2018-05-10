#include <bits/stdc++.h>
using namespace std;
#define MAXN 25005

int m, n, s, e, q, index, group;
vector<int> graph[MAXN];
int DFN[MAXN]; // ����DFN(u)Ϊ�ڵ�u�����Ĵ�����(ʱ���);
int Low[MAXN]; // Low(u)Ϊu��u�������ܹ�׷�ݵ��������ջ�нڵ�Ĵ���š�
int belong[MAXN];
bool inStack[MAXN];
stack<int> stk;

void Init() {
    index = group = 0;
    memset(DFN, -1, sizeof(DFN));
    memset(inStack, false, sizeof(inStack));
    for (int i = 0; i < MAXN; ++i) graph[i].clear();
}

void tarjan(int u, int fa) {
    DFN[u] = Low[u] = ++index;
    stk.push(u), inStack[u] = true;
    int v, size = graph[u].size();
    for (int i = 0; i < size; ++i) {
        v = graph[u][i];
        if (DFN[v] == -1) // δ����
        {
            tarjan(v, u);
            Low[u] = min(Low[u], Low[v]);
        }
        else if (inStack[v] && v != fa)
            Low[u] = min(Low[u], DFN[v]);
    }

    if (DFN[u] == Low[u]) {
        ++group;
        do {
            v = stk.top();
            stk.pop(), inStack[v] = false;
            belong[v] = group;
        } while(u != v);
    }
}

void solve() {
    for (int i = 1; i <= m; ++i)
        if (DFN[i] == -1) tarjan(i, -1);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    Init();
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &s, &e);
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    solve();
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &s, &e);
        if (belong[s] == belong[e])
            puts("Yes");
        else puts("No");
    }

    return 0;
}
