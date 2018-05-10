#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 205

double map[MAXN][MAXN];

struct Frog{
	int x, y;
} f[MAXN];

double dis(Frog a, Frog b) {
	double dx = 1.0 * (a.x - b.x);
	double dy = 1.0 * (a.y - b.y);
	return sqrt(dx*dx + dy*dy);
}

int main() {
	freopen("in.txt", "r", stdin);
	int n, X = 0;
	while(scanf("%d", &n), n)
	{
		for (int i=0; i<n; i++)
			scanf("%d%d", &f[i].x, &f[i].y);

		for (int i=0; i<n; i++) {
			for (int j=0 ;j<n; j++) {
				if (i==j)
					map[i][j] = 0;
				else
					map[i][j] = dis(f[i], f[j]);
			}
		}

		for (int k=0; k<n; k++)
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					map[i][j] = min(map[i][j], max(map[i][k], map[k][j]));

		printf("Scenario #%d\n", ++X);
		printf("Frog Distance = %.3f\n\n", map[0][1]);
	}

	return 0;
}
