#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MX 505
#define INF 0x3f3f3f3f

int n, m, s, e;

int G[MX][MX];	//�ڽӾ���
bool vis[MX];	//�Ƿ����
int pre[MX];	//
int dis[MX];	//���·�� lowcost
int score[MX];	// ��¼��ʼ��ֵ

void Dijkstra(int s)   // v0 Ϊ���
{
    for (int i=0; i<n; i++) {
        dis[i] = INF;
        vis[i] = 0;
        pre[i] = 0;
    }

    pre[s] = score[s];
    dis[s] = 0;

    for (int i=0; i<n; i++) {
        int k = -1, min = INF;
        // ÿ������֪·����̵ĵ�
        for (int j=0; j<n; j++) {
            if(!vis[j] && dis[j] < min) {
                min = dis[j];
                k = j;
            }
        }
        // ���еĵ㶼�Ѿ�������
        if (k == -1)
            break;
        vis[k] = 1;

        for (int j=0; j<n; j++) {
            if (!vis[j]) {
                if (dis[j] > dis[k] + G[k][j]) {
                    dis[j] = dis[k] + G[k][j];
                    pre[j] = pre[k] + score[j];
                }
                else if(dis[j] == dis[k] + G[k][j]) {
                    pre[j] = max(pre[j], pre[k] + score[i]);
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i=0; i<n; i++)
        scanf("%d", &score[i]);

    memset(G, INF, sizeof(G));

    int x, y, v;
    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &x, &y, &v);
        G[x][y] = G[y][x] = v;
    }

    Dijkstra(s);

    printf("%d %d\n", dis[e], pre[e]);

    return 0;
}
