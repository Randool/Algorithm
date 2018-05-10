#include <cstdio>
#include <algorithm>
using namespace std;
int med[105];
int main() {
	int C, n, V, W, volume, t, i;
	double density;
	scanf("%d",&C);
	while(C--) {
		scanf("%d%d%d",&n,&V,&W);
		for(i=1; i<=n; i++)
			scanf("%d",&med[i]);
		sort(med+1,med+1+n);
		if(med[1]>=W && med[n]>W) {
			printf("0 0.00\n");
			continue;
		}
		volume=V;
		density=med[1];
		for(i=2; i<=n; i++) {
			if(density + med[i]*1.0 <= 1.0*W*i) {
				volume += V;
				density += med[i]*1.0;
			}
		}
		density = density / (volume*1.0/V);
		printf("%d %.2lf\n",volume,density*0.01);
	}
	return 0;
}
