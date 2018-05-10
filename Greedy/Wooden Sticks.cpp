#include <cstdio>
#include <algorithm>
using namespace std;

struct Wooden {
	int l, w;
	bool flag;
} wood[5005];

bool cmp(Wooden a, Wooden b) {
	if(a.l > b.l) return 1;
	else if(a.l==b.l) return a.w > b.w;
	return 0;
}

int main() {
	int N, n, s;
	scanf("%d",&N);
	while(N--) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d",&wood[i].l,&wood[i].w);
			wood[i].flag=0;
		}
		sort(wood+1, wood+1+n,cmp);
		s=0;
		for(int i=1; i<=n; i++) {
			if(wood[i].flag==1)
				continue;
			int Min = wood[i].w;
			for(int j=i+1; j<=n; j++) {
				if(wood[j].flag==0 && wood[j].w<=Min) {
					Min=wood[j].w;
					wood[j].flag=1;
				}
			}
			s++;
		}
		printf("%d\n",s);
	}

	return 0;
}
