#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100005
#define sf(n)   scanf("%d", &n)
#define sff(a,b) scanf("%d%d", &a, &b)
using namespace std;

int d[MAXN];
int N, a, b;

int lowbit(int x) {
	return x & (-x);
}

void update(int x, int num) {
	while(x <= N) {
		d[x] += num;
		x += lowbit(x);
	}
}

int getSum(int x) {
	int s = 0;
	while(x > 0) {
		s += d[x];
		x -= lowbit(x);
	}
	return s;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while(sf(N) && N)
    {
        memset(d,0,sizeof(d));
        for(int i=0; i<N; i++)
        {
            sff(a,b);
            update(a, 1);
            update(b+1, -1);
        }
        for(int i=1; i<N; i++)
            printf("%d ", getSum(i));
        printf("%d\n", getSum(N));
    }
	return 0;
}
