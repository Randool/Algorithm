/*紫薯P365-----噪音恐惧症*/
#include <cstdio>
#define MX 505
#define INF 999999
using namespace std;

int d[MX][MX];
int min(int a, int b){
	return a>b ? b:a;
}
int max(int a, int b){
	return a<b ? b:a;
}
int main() {
	int C,S;
	printf("分别输入点数和边数：\n");
	while(~scanf("%d%d",&C,&S))
	{
		for(int i=1; i<=C; i++)
			for(int j=1; j<=C; j++)
				d[i][j] = (i==j ? 0 : INF);
		printf("输入边及边权：\n");
		for(int i=1; i<=S; i++) {
			int s,e,t;
			scanf("%d%d%d",&s,&e,&t);
			d[s][e] = d[e][s] = t;
		}
		for(int k=1; k<=C; k++)
			for(int i=1; i<=C; i++)
				for(int j=1; j<=C; j++)
					d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
		int start, end;
		printf("起点及终点：");
		scanf("%d%d", &start, &end);
		printf("噪音最小是：%d\n", d[start][end]);
	}
}
