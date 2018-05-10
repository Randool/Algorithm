/*Tempter of the Bone*/
#include <cstdio>
#include <iostream>

char maze[8][8];
int to[4][2]= {{0,-1},{0,1},{1,0},{-1,0}};
int M, N, T, wall, flag, x, y/*当前坐标*/, dx, dy/*目的地*/;

void Show();

int abs(int x) {
	return x>=0 ? x : -x;
}
void DFS(int x, int y, int cnt) {
	//终止条件
	if(x>M || y>N || x<0 || y<0) //出界
		return;
	if(x==dx && y==dy && cnt==T) { //到达终点
		flag=1;
		return;
	}
	int sx=abs(dx-x), sy=abs(dy-y);
	int tem = (T-cnt)-(sx+sy); // (T-cnt)表示剩余时间
	//如果剩余时间不足以走到终点或者 tem是奇数的话，走不到,根据奇偶性剪枝
	if(tem<0 || tem&1)
		return;
	//向四个方向走：
	/*for(int i=0; i<4; i++) {
		if( maze[ x+to[i][0] ][ y+to[i][1] ] != 'X') {
			maze[ x+to[i][0] ][ y+to[i][1] ]='X';//如果走，这个地方不能重新到达
			//Show();
			DFS(x+to[i][0],y+to[i][1],cnt+1);
			maze[ x+to[i][0] ][ y+to[i][1] ]='.';//如果不走，复原
		}
	}*/
	if(maze[x+1][y]!='X'){
		maze[x+1][y]='X';
		DFS(x+1,y,cnt+1);
		maze[x+1][y]='.';
	}
	if(maze[x][y+1]!='X'){
		maze[x][y+1]='X';
		DFS(x,y+1,cnt+1);
		maze[x][y+1]='.';
	}
	if(maze[x-1][y]!='X'){
		maze[x-1][y]='X';
		DFS(x-1,y,cnt+1);
		maze[x-1][y]='.';
	}
	if(maze[x][y-1]!='X'){
		maze[x][y-1]='X';
		DFS(x,y-1,cnt+1);
		maze[x][y-1]='.';
	}
	return;
}

int main() {
	while(~scanf("%d%d%d%*c",&M,&N,&T)) {
		if(!M || !N || !T) break;
		wall = 0;
		for(int i=1; i<=M; i++) {
			for(int j=1; j<=N; j++) {
				scanf("%c",&maze[i][j]);
				if(maze[i][j]=='S') {
					x=i;
					y=j;
				} else if(maze[i][j]=='D') {
					dx=i;
					dy=j;
				} else if(maze[i][j]=='X')
					wall++;
			}
			getchar();
		}
		//Show();
		if(M*N-wall<T) {
			printf("NO\n");
			continue;
		}
		flag=0;
		maze[x][y]='X';
		DFS(x,y,0);
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

void Show() {
	for(int i=1; i<=M; i++) {
		for(int j=1; j<=N; j++)
			printf("%c",maze[i][j]);
		printf("\n");
	}
}
