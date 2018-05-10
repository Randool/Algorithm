#include <cstdio>
#include <iostream>
#define MAXN 105
using namespace std;

int m,n,sum;
int Move[8][2] = {
	{0,1},{0,-1},{1,0},{-1,0},
	{1,1},{1,-1},{-1,1},{-1,-1}
};
char map[MAXN][MAXN];

void dfs(int i, int j) {
	if( i<0 || j<0 || i>m || j>n ) return;
	if(map[i][j] != '@') return;
	map[i][j] = '!';
	for(int t=0; t<8; t++) {
		int x = i + Move[t][0];
		int y = j + Move[t][1];
		dfs(x,y);
	}
}
void Show() {
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
}
int main() {
	while(cin>>m>>n)
	{
		if(m==0 || n==0)
			break;
		sum = 0;
		getchar();
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++)
				scanf("%c",&map[i][j]); getchar();
		}
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(map[i][j] == '@') {
					dfs(i,j);
					//Show();
					sum++;
				}
			}
		}
		//Show();
		printf("%d\n",sum);
	}

	return 0;
}
/*
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
*/
