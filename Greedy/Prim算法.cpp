#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
const int INF = 999999;
using namespace std;

int N, M; //N为点的数量，M为边的数量
int n1, n2, cost, ans;
int map[1002][1002];
//b1确定是否添加结点到 node1中，b2确定已存在的结点是否已经被选择
bool b1[1002], b2[1002];
vector<int> node1, node2;

void Init();

int Prim(int v1) {
	b2[node1[v1]]=1;
	ans=0;
	int size = node1.size(), t;
	for(int i=1; i<=size; i++) {
		int min = INF;
		for(int j=1; j<=size; j++) {
			if(min > map[i][j] && b2(node1[j])==0)
				min = map[i][j];
				t = j;
		}
		ans += map[i][j];
		map[i][j] = map[j][i] = INF;
		
	}
}

int main() {
	while(~scanf("%d%d",&N,&M)) {
		Init();
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		node1.push_back(0);
		for(int i=1; i<=M; i++) {
			scanf("%d%d%d", &n1, &n2, &cost);
			if(b1[n1]==0) {
				b1[n1]=1;
				node1.push_back(n1);
			}
			if(b1[n2]==0) {
				b1[n2]=1;
				node1.push_back(n2);
			}
			if(map[n1][n2] > cost)
				map[n1][n2] = map[n2][n1] = cost;
		}
		printf("%d\n",Prim(1));
	}

	return 0;
}

void Init() {
	for(int i=0; i<=N; i++)
		for(int j=0; j<=N; j++)
			map[i][j] = INF;
}
