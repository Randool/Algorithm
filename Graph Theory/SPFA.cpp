#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 505
#define INF 0x3f3f3f3f
using namespace std;

struct Node {
    int to;
    int weight;
    Node *next;
};
Node* List[MAXN];
Node *temp;
bool inq[MAXN];
int dist[MAXN];
int score[MAXN];
int sum[MAXN];

void SPFA(int start)
{
	queue<int> Q;
    int u, v;
    memset(inq, 0, sizeof(inq));
    memset(dist, 0x3f, sizeof(dist));

    Node* temp;
    dist[start] = 0;
    Q.push(start), inq[start] = 1;

    while( !Q.empty() ) {
        u = Q.front();
		Q.pop(), inq[u] = 0;
        temp = List[u];
        while( temp != NULL ) {
            v = temp->to;
			if (dist[v] > dist[u] + temp->weight) {
                dist[v] = dist[u] + temp->weight;
                sum[v] = sum[u] + score[v];
                if (!inq[v]) {
					Q.push(v), inq[v] = 1;
				}
            }
            else if(dist[v] == dist[u] + temp->weight) {
            	sum[v] = max(sum[v], sum[u] + score[v]);
			}
			temp = temp->next;
        }
    }
}

void addedge(int x, int y, int z) {
	temp = new Node;	//如果new放在循环外，其实指向的都是一个Node
    temp->to = y;
    temp->weight = z;
    temp->next = NULL;
    if (List[x] == NULL) List[x] = temp;
    else { temp->next = List[x]; List[x] = temp; }
}

int main()
{
	// freopen("in.txt", "r", stdin);
    int n, m, start, end, x, y, z;
    while(~scanf("%d%d%d%d", &n, &m, &start, &end))
    {
        for (int i=0; i<n; ++i) {
            scanf("%d", &score[i]);
        	sum[i] = score[i];
		}
        for (int i=0; i<m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
        	addedge(x, y, z);
        	addedge(y, x, z);
        }
        SPFA(start);
        printf("%d %d\n", dist[end], sum[end]);
        // 这一段是关键，没有释放这一段，答案会错
        for (int i=0; i<=n; ++i) {
            temp = List[i];
            while( temp != NULL ) {
                List[i] = temp->next;
                delete temp;
                temp = List[i];
            }
        }
    }
    return 0;
}
