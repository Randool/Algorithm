#include <cstdio>
#include <cmath>
#define MAXN 500005

bool prime[MAXN];
long long su[5000];

int main() {
	int n, T, cnt;
	scanf("%d", &n);
	prime[0] = prime[1] = 0;
	prime[2] = 1;

	for(int i=3; i<=n; i++)
		prime[i] = (i%2==0 ? 0 : 1);

	T = sqrt(n)+1;
	
	//筛去 su[j]*i 范围中的素数 
	cnt = 1;
	for(int i=2; i<=n; i++) {
		if(prime[i])
			su[cnt++] = i;
		//从已有的素数中挑选 
		for(int j=1; j<cnt && su[j]*i<=n; j++)
			prime[su[j]*i] = 0;
	}

	cnt = 0;
	for(int i=1; i<=n; i++) {
		if(prime[i]) {
			printf("%d ",i);
			cnt++;
		}
		if(cnt==10) {
			printf("\n");
			cnt=0;
		}
	}

	return 0;
}
