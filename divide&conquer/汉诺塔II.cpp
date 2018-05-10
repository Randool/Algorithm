#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
typedef unsigned long long LL;
using namespace std;

LL hanoi[70];

void Hanoi() {
	memset(hanoi, 0x7f, sizeof(hanoi));
	hanoi[1] = 1;
	hanoi[2] = 3;
	for (int i=3; i<=65; ++i)
		for (int j=1; j<=i; ++j)
			hanoi[i] = min(hanoi[i], hanoi[i-j]*2 + (LL)(pow(2, j)) - 1);
}

int main() {
	int N;
	Hanoi();
	while (~scanf("%d", &N)) {
		printf("%lld\n", hanoi[N]);
	}
	return 0;
}
