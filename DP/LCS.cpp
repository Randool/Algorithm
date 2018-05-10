#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

char a[1005];
char b[1005];
int dp[1005][1005];
int path[1005][1005];

void out(int i, int j) {
	if(i==0 || j==0) return;
	if(path[i][j]==0) {
		printf("%c", a[i-1]);
		out(i-1, j-1);
	}
	else if(path[i][j] == -1)
		out(i, j-1);
	else
		out(i-1, j);
}

int main() {
	int lena, lenb, i, j;

	while(scanf("%s%s", &a, &b) == 2) {
		memset(dp, 0, sizeof(dp));
		memset(path,0,sizeof(path));

		lena = strlen(a);
		lenb = strlen(b);

		for(i = 1; i <= lena; i++) {
            for(j = 1; j <= lenb; j++) {
				if(a[i-1] == b[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
					path[i][j] = 0;
				}
				else if(dp[i-1][j] > dp[i][j-1]) {
					dp[i][j] = dp[i-1][j];
					path[i][j] = 1;
				}
				else if (dp[i-1][j] < dp[i][j-1]) {
					dp[i][j] = dp[i][j-1];
					path[i][j] = -1;
				}
				else {
                    dp[i][j] = dp[i-1][j];
                    path[i][j] = (a[i-1] < b[j-1] ? -1 : 1);
				}
			}
		}

		// printf("%d\n", dp[lena][lenb]);
		out(lena, lenb);
		printf("\n");
	}
	return 0;
}
/*
aedf
adef
adef
aedf
*/
