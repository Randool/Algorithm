#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 101
using namespace std;

int b[3], half;
int map[MAXN][MAXN][MAXN];

struct node {
	int cur[3], s;
} p,temp;

void bfs() {
	queue<node> q;
	p.cur[0] = b[0];
	p.s = p.cur[1] = p.cur[2] = 0;
	q.push(p);
	while(!q.empty()) {
		p = q.front();
		q.pop();
		for(int i=0; i<3; i++) {
			if(p.cur[i] > 0) //有水才可倒
				for(int j=0; j<3; j++) {
					if(i == j) continue;
					temp = p;
					if(temp.cur[i] > b[j] - temp.cur[j]) { //可以倒满
						temp.cur[i] -= b[j] - temp.cur[j];
						temp.cur[j] = b[j];
					} else { //倒不满
						temp.cur[j] += temp.cur[i];
						temp.cur[i] = 0;
					}

					if(!map[temp.cur[0]][temp.cur[1]][temp.cur[2]]) {
						map[temp.cur[0]][temp.cur[1]][temp.cur[2]] = 1;
						temp.s++;
						//printf("%d %d %d %d\n", temp.cur[0], temp.cur[1], temp.cur[2], temp.s);
						if((temp.cur[0]==half && temp.cur[1]==half) || (temp.cur[0]==half && temp.cur[2]==half) ||
						        (temp.cur[1]==half && temp.cur[2]==half)) {
							printf("%d\n",temp.s);
							return;
						}
						q.push(temp);
					}
				}
		}
	}
	printf("NO\n");
}

int main () {
	while(~scanf("%d%d%d",&b[0], &b[1], &b[2])) {
		if(b[0]+b[1]+b[2] == 0)	break;
		if(b[0]%2) {
			printf("NO\n");
			continue;
		}
		memset(map,0,sizeof(map));
		map[b[0]][b[1]][b[2]] = 1;
		half = b[0]/2;
		bfs();
	}
	return 0;
}
