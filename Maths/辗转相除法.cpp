#include <cstdio>
using namespace std;

int k;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int judge(int* X) {
	X[2] /= gcd(X[2], X[1]);
	for(int i=3; i<=k; i++)
		X[2] /= gcd(X[i], X[2]);
	return X[2] == 1;
}

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b)==2) {
		printf("最大公因数：%d\n", gcd(a,b));
		printf("最小公倍数：%d\n", a/gcd(a,b)*b);
	}
	return 0;
}
