#include <cstdio>
#include <cstring>
#include <iostream>
const int maxn = 10;
using namespace std;

int n, k;
int cnt, num;	//ans是最终答案，num是已放的棋子数目 
int placed[maxn]; // 记录该列是否放过棋子 
char board[maxn][maxn];

void DFS(int i) {
	if(k==num) { //终止条件1：还没达到边缘就放完了棋子  
		cnt++;
		return;
	}
	if(i>=n) //终止条件2：超出边缘 
		return;
	for(int j=0; j<n; j++) {
		if(placed[j]==0 && board[i][j]=='#') {
			// 如果选择在 j 放棋子 
			placed[j]=1;
			num++;
			DFS(i+1);
			// 如果选择在 j 不放棋子
			placed[j]=0;
			num--; 
		}
	}
	DFS(i+1); //下一行  
}

int main() {
	while(~scanf("%d%d",&n,&k)) {
		getchar(); //吃回车 
		if(n==-1 && k==-1) break;		
		for(int i=0; i < n; i++){
			for(int j=0; j < n; j++)
				scanf("%c",&board[i][j]);
				getchar(); //吃回车 
		}
		memset(placed,0,sizeof(placed));
		cnt = 0; num = 0;
		DFS(0);
		printf("%d\n",cnt);
	}
	return 0;
}

