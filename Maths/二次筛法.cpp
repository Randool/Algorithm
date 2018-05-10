/*二次筛法*/
#include <cstdio>
#include <cmath>
#define N 50005
#define MAXN 0xfffffff
using namespace std;

//先找出小于50000范围内的素数
//再用50000内素数筛掉大合数
//50000^2 > 2^32

int su[MAXN];
bool prime[MAXN];

int main() {
	int T, n, cnt=1, a0, a1;
	scanf("%d",&n);
	T = sqrt(n) + 1;
	prime[1] = 0;
	prime[2] = 1;
	for(int i=3; i<=N; i++)
		prime[i] = (i%2==0 ? 0 : 1 );
	for(int i=2; i<=N; i++) {
		if(prime[i])
			su[cnt++] = i;
		for(int j=1; j<cnt && su[j]*i<=N; j++)
			prime[su[j]*i] = 0;
	}

	while(cin>>a0>>a1)
	{
		
		
		
	}

	return 0;
}
