#include <cstdio>
#include <algorithm>
using namespace std;
// 数 p和 w(1<=p<=25,1<=w<=100)，
//分别表示单价和对应大米的重量。
struct Dm {
	int p, w;
} dm[1005];

cmp(const Dm a, const Dm b) {
	return a.p < b.p;
}

int main() {
	int C;
	scanf("%d",&C);
	while(C--) {
		int n,m; //n表示经费的金额，m表示大米的种类
		scanf("%d%d",&n,&m);
		double money = (double)n, weight = 0.0;
		for(int i=1; i<=m; i++)
			scanf("%d%d",&dm[i].p,&dm[i].w);
		sort(dm+1, dm+1+m, cmp);
		int t=1;
		while(money > 0.0) {
			if(money <= (double)dm[t].p*dm[t].w) {
				weight += money / (double)dm[t].p;
				money = 0.0;
			} else {
				weight += (double)dm[t].w;
				money -= (double)dm[t].p*dm[t].w;
				t++;
			}
		}
		printf("%.2lf\n",weight);
	}

	return 0;
}
