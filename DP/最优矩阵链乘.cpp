#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 55
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;

int n;
int mat[MAXN];
int G[MAXN][MAXN];

void MatrixChain(int n, int* mat) {
	memset(G, 0, sizeof(G));
	for (int l=2; l<=n; ++l) {
		for (int i=1; i<=n; ++i) {
			int j = i + l - 1;
			int tmp = INF;
			for (int k=i; k<j; ++k) {
				tmp = min(tmp, G[i][k] + G[k+1][j] + mat[i-1] * mat[k] * mat[j]);
			}
			G[i][j] = tmp;
		}
	}
}

void Show(int n) {
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (j >= i)
				printf("%5d ", G[i][j]);
			else
				printf("%5d ", 0);
		}
		printf("\n");
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	/*
	6
	30 35 15 5 10 20 25
	*/
	scanf("%d", &n);
	for (int i=1; i<=n+1; i++)
		scanf("%d", &mat[i]);
	MatrixChain(n, mat);
	printf("Optimization : %d\n", G[1][n]);
	Show(n);
	return 0;
}
