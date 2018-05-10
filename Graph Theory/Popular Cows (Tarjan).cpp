#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 10005

struct Node {
    vector<int> next;
} cows[MAXN];

int groupCnt[MAXN];
int DFN[MAXN], Low[MAXN], belong[MAXN];
int index = 0, result, group = 0;
bool inStack[MAXN], vis[MAXN];
stack<int> S;

void tarjan(int u) {
    DFN[u] = Low[u] = ++index;
    S.push(u), inStack[u] = true;
    int v, size = cows[u].next.size();
    for (int i = 0; i < size; ++i) {
        v = cows[u].next[i];
        if (!DFN[v]) {  // 无访问
            tarjan(v);
            if (Low[v] < Low[u]) Low[u] = Low[v];
        }
        else if (inStack[v] && DFN[v] < Low[u]) { // 已访问且还在栈中
            Low[u] = DFN[v];
        }
    }
    if (DFN[u] == Low[u]) {
        ++group;
        do {
            v = S.top();
            S.pop(), inStack[v] = false;
            belong[v] = group;
            groupCnt[group] ++;
        } while (u != v);
    }
}

/*
6 6
2 1
2 3
3 4
4 6
4 5
5 1
*/
int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    memset(DFN, 0, sizeof(DFN));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        cows[a].next.push_back(b);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) tarjan(i);
    for (int i = 1; i <= n; ++i)
    {
        if (cows[i].next.empty() && groupCnt[belong[i]] == 1)
            ++result;
    }
    printf("%d\n", result);
    return 0;
}
