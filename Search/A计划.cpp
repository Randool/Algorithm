#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int n,m,t;
char Map[2][15][15];
struct Node{
    int x, y, t;
    Node(int X, int Y, int T){x = X; y = Y; t = T;}
};
int Go[6][3]= {{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};

bool Judge(Node p) {
    if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m || p.t > t)
        return 0;
    return 1;
}

void bfs()
{
    Node start(0,0,0);
    queue<Node> q;
    q.push(start);
    while(!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        if (Judge(tmp)==0) return;
        for (int )
    }

}

int main()
{
    freopen("in.txt", "r", stdin);
    int C;
    scanf("%d", &C);
    while(C--)
    {

        scanf("%d%d%d", &n, &m, &t);
        for (int i=0; i<n; i++)
        {
            scanf("%s", &Map[0][i]);
        }
        getchar();
        for (int i=0; i<n; i++)
        {
            scanf("%s", &Map[1][i]);
        }
        bfs();
    }
    return 0;
}
