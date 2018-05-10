#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100005
using namespace std;
bool vis[MAXN];

bool judge(int step, int mod)
{
    memset(vis, 0, sizeof(vis));
    int cnt = 0, x = 0, y;
    while (!vis[x])
    {
        vis[x] = 1;
        ++cnt;
        x = (x + step) % mod;
    }
    if (cnt != mod) return 0;
    else return 1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int step, mod;
    while (~scanf("%d%d", &step, &mod))
    {
        printf("%10d%10d", step, mod);

        if (judge(step, mod))
            printf("    Good Choice\n\n");
        else
            printf("    Bad Choice\n\n");
    }
    return 0;
}
