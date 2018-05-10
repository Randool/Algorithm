#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int mass[10005];
//6 6
//1 2 3 4 5 5
int main() {
	int N,V;
	scanf("%d%d",&N,&V);
	for(int i=1; i<=N; i++)
		scanf("%d",&mass[i]);
	sort(mass+1, mass+1+N);
	//for (int i=1; i<=3; i++) cout << mass[i] << " ";
	int p=1, q=N, ans=0;
	while(p<q) {
		if(mass[p]+mass[q] <= V) {
			ans++;
			p++;
			q--;
		}
		else {
			ans++;
			q--;
		}
	}
	if (p==q) ans ++;
	printf("%d\n",ans);

	return 0;
}
