#include <cstdio>
#include <queue>
#include <iostream>
#define MAXN 55
using namespace std;

int K, A, B, C, T;
int Move[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int map[MAXN][MAXN][MAXN];
struct Node {
	int x,y,z,t;
	Node(int X, int Y, int Z, int T) {
		x=X, y=Y, z=Z, t=T;
	}
};

void bfs() {
	queue<Node> q;
	Node n(0,0,0,0);
	map[0][0][0] = 1;
	q.push(n);
	while(!q.empty())
	{
		Node u = q.front();
		q.pop();
		if(u.x==A-1 && u.y==B-1 && u.z==C-1 && u.t<=T) {
			printf("%d\n",u.t);
			return;
		}
		if(u.t > T) break;
		for(int i=0; i<6; i++) {
			Node v = u;
			v.x += Move[i][0];
			v.y += Move[i][1];
			v.z += Move[i][2];
			v.t++;
			if(!map[v.x][v.y][v.z] && (v.x<A && v.x>=0) && (v.y<B && v.y>=0) && (v.z<C && v.z>=0) && (v.t<=T))
			{
				if(u.x==A-1 && u.y==B-1 && u.z==C-1 && u.t<=T) {
					printf("%d\n",u.t);
					return;
				}
				q.push(v);
				map[v.x][v.y][v.z] = 1;
			}
		}
	}
	printf("-1\n");
}
void Scanf() {
	for(int i=0; i<A; i++)
		for(int j=0; j<B; j++)
			for(int k=0; k<C; k++)
				scanf("%d",&map[i][j][k]);
}
int main() {
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d%d%d%d",&A,&B,&C,&T);
		Scanf();
		//printf("Searching...\n");
		bfs();
	}
	return 0;
}

