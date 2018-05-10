#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Treasure{
	double p, v; //宝贝的单价和对应的体积 
} tre[105];

cmp(const Treasure &a, const Treasure &b) {
	return a.p/a.v > b.p/b.v;
}

int main() {
	int V,n;
	while(scanf("%d%d",&V,&n) && V!=0) {
		for(int i=1; i<=n; i++)
			scanf("%lf%lf", &tre[i].p, &tre[i].v);
		sort(tre+1,tre+1+n,cmp);
		while(V>0.0)
		
		
	}
	
	return 0;
}
