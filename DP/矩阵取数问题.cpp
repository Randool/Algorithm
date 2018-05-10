#include <iostream>
#include <cstring>
using namespace std;
const int N = 505;
long long a[N][N];

int main()
{
	int n, i, j;
	while(cin >> n) {
		memset(a, 0, sizeof(a));
		for(i = 1; i <= n; i ++) {
		    for(j = 1; j <= n; j ++) {
				cin >> a[i][j];
				a[i][j] += max( a[i-1][j] , a[i][j-1] );
			}
		}
		cout << a[n][n] << endl;
	}
	return 0;
}
