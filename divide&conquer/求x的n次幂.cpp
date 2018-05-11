/*****ÇóxµÄn´ÎÃÝ*****/
#include <cstdio>

long long power(int x, int n) {
	if(n==1) return x;
	else if(n%2 == 0)
		return power(x, n/2) * power(x, n/2);
	else
		return power(x, (n+1) / 2) * power(x, (n-1) / 2);
}

int main() {
	int x, n;
	while(scanf("%d%d",&x,&n))
		printf("%lld\n",power(x,n));
	return 0;
}
