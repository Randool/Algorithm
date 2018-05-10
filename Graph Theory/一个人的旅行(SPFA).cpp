#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#define MAXN 1005
#define INF 0x3f3f3f3f
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
using namespace std;

struct Node{
	int to;
	int weight;
	Node *next;
};
Node* List[MAXN];
Node* temp = NULL;
bool inq[MAXN];
int dist[MAXN];

void SPFA(int start) {
	queue<int> Q;
	Node* temp = NULL;
	dist[start] = 0;
	Q.push(start), inq[start] = 1;
	while( !Q.empty() )
	{
		int u = Q.front();
		Q.pop(), inq[u] = 0;
		temp = List[u];
		while( temp != NULL )
		{
			int v = temp->to;
			if (dist[v] > dist[u] + temp->weight)
			{
				dist[v] = dist[u] + temp->weight;
				if ( !inq[v] ) {
					Q.push(v), inq[v] = 1;
				}
			}
			temp = temp->next;
		}
	}
}

void addedge(int a, int b, int c) {
	temp = new Node;
	temp->to = b;
	temp->weight = c;
	temp->next = NULL;
	if (List[a] == NULL) List[a] = temp;
	else {
		temp->next = List[a];
		List[a] = temp;
	}
}

int main()
{
	freopen("一个人的旅行.txt", "r", stdin);
	int t, s, d, a, b, c;
	while(~sfff(t,s,d))
	{
		memset(inq, 0, sizeof(inq));
		memset(dist,0x3f,sizeof(dist));
		for (int i=0; i<t; ++i)
		{
			sfff(a,b,c);
			addedge(a, b, c);
			addedge(b, a, c);
		}
		for (int i=0; i<s; ++i)
		{
			scanf("%d", &a);
			addedge(a, 0, 0);
			addedge(0, a, 0);
		}
		SPFA(0);
		int ans = INF;
		for (int i=0; i<d; ++i) {
			scanf("%d", &a);
			if (dist[a] < ans) ans = dist[a];
		}
		
		printf("%d\n", ans);
		
		for (int i=0; i<=1000; ++i) {
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
