#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define MAXN 55
#define INF 0x3f3f3f3f
using namespace std;

int T, N;
int map[MAXN][MAXN];

void getData() {
	char ss[MAXN];
	for (int i=0; i<N; i++) {
		scanf("%s", ss);
		int cnt = 0;
		for (int k=0; k<N; k++) {
			if(ss[k]=='Y')
				map[i][k] = ++cnt;
			else
				map[i][k] = INF;
		}
	}
}

void Show() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}

void Floyd() {
	for (int k=0; k<N; k++)
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		getData();
		Floyd();
		if(map[0][N-1] < INF)
			printf("%d\n", map[0][N-1]);
		else
			printf("-1\n");
	}
	return 0;
}
