/*大整数取模*/
/*输入正整数a、n和 m，输出 a^n mod m; a,n,m<=10^9 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int pow_mod(int a, int n, int m) {
	int ans = 1;
	for(int i=1; i<=n; i++) {
		//printf("%d ", ans);
		ans = (int)((long long)ans * a % m);
	}
	return ans;
}

int qpow_mod(int a, int n, int m) {
	if(n == 0) return 1;
	int x = pow_mod(a, n/2, m);
	long long ans = (long long)x * x % m;
	if(n % 2 == 1) ans *= a;
	return ans;
}

int main() {
	int a, n, m;
	printf("输入正整数a、n和 m，输出 a^n mod ：\n");
	while(scanf("%d%d%d",&a,&n,&m)==3)
		printf("%d^%d mod %d = %d\n\n", a, n, m, qpow_mod(a, n, m));
	
	return 0;
}
