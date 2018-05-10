#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int s[3001];
int main() {
	int N, maxn, t;
	while(~scanf("%d",&N)) {
		s[0] = -99999;
		for(int i=1; i<=N; i++)
			scanf("%d",&s[i]);
		sort(s+1,s+1+N);
		maxn=1;
		t=1;
		for(int i=1; i<=N; i++) {
			if(s[i]==s[i-1]) t++;
			else t=1;
			if(t>maxn) maxn=t;
		}
		printf("%d\n",maxn);
	}
	
	return 0;
}
