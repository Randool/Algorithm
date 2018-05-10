#include <cstdio>
#include <cstring>
using namespace std;
int time[10005];
int main() {
	int n;
	while(~scanf("%d",&n)) {
		long long p, q, begin=1000000000, end=0;
		int ans=0;
		memset(time,0,sizeof(time));
		for(int i=1;i<=n;i++){
			scanf("%ld%ld",&p,&q);
			if(begin>p) begin=p;
			if(end<q) end=q;
			for(int j=p; j<q; j++)
				time[j]++;
		}
		for(int i=begin; i<=end; i++)
			if(time[i]>ans)
				ans = time[i];
		printf("%d\n",ans);
	}
	
	return 0;
} 
