// POJ 2083
// https://vjudge.net/problem/POJ-2083
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1000
using namespace std;

char G[MAXN][MAXN];
int mid_x = 500, mid_y = 500;

int power(int a, int b)
{
	if (b==0) return 1;
	return power(a, b-1) * a;
}

void Draw(int n, int x, int y) {
	if (n == 1) {
		G[x][y] = 'X';
		return;
	}
	int pace = power(3, n-2);
	Draw(n-1, x, y);
	Draw(n-1, x+pace, y+pace);
	Draw(n-1, x, y+pace*2);
	Draw(n-1, x+pace*2, y);
	Draw(n-1, x+pace*2, y+pace*2);
}

int main()
{
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		int size = power(3, n-1);
		for (int i=0; i<size; ++i)
			for (int j=0; j<size; ++j)
				G[i][j] = ' ';
		
		Draw(n, 0, 0);
		
		for (int i=0; i<size; ++i)
			G[i][size] = '\0';
		
		for (int i=0; i<size; ++i)
			puts(G[i]);

		puts("-");
	}
	return 0;
}
