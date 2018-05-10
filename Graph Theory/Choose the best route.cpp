#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;

struct Node {
	int to;
	int weight;
	Node* next;
};
Node* List[MAXN];
int inq[MAXN];
int dist[MAXN];

void SPFA(int start) {
	queue<int> Q;
	dist[start] = 0;
	Node* temp = NULL;
	Q.push(start), inq[start] = 1;
	while( !Q.empty() ) {
		int u = Q.front();
		//cout << "front : " << u << endl;
		Q.pop(), inq[u]  =0;
		temp = List[u];
		while( temp != NULL ) {
			int v = temp->to;
			if (dist[v] > dist[u] + temp->weight) {
				dist[v] = dist[u] + temp->weight;
				//cout << u << "->" << v << " " << dist[v] << endl;
				if( !inq[v] ) {
					Q.push(v), inq[v] = 1;
				}
			}
			temp = temp->next;
		}
	}
}

int main() {
	freopen("best route.txt","r",stdin);
	int n, m, end, start, p, q, t, num;
	Node* temp = NULL;
	while(~scanf("%d%d%d", &n, &m, &end)) {
		for (int i=0; i<=n; ++i)
			dist[i] = INF;
		memset(inq,0,sizeof(inq));
		for (int i=0; i<m; ++i) {
			scanf("%d%d%d", &p, &q, &t);
			temp = new Node;
			temp->to = q;
			temp->weight = t;
			temp->next = NULL;
			if (List[p]==NULL) {
				List[p] = temp;
			} else {
				temp->next = List[p];
				List[p] = temp;
			}
		}
		scanf("%d", &num);
		for (int i=0; i<num; ++i) {
			scanf("%d", &start);
			temp = new Node;
			temp->to = start;
			temp->weight = 0;
			temp->next = NULL;
			if (List[0]==NULL) {
				List[0] = temp;
			} else {
				temp->next = List[0];
				List[0] = temp;
			}
		}
		dist[0] = 0;
		SPFA(0);
		if (dist[end] != INF) printf("%d\n", dist[end]);
		else puts("-1");

		// 释放内存，若不释放答案会错
		for (int i=0; i<n; ++i) {
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
