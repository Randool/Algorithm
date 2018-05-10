/*八皇后问题*/
#include <cmath>
#include <cstdio>
#define MAXN 10
using namespace std;

int ans=0, Q=15/*皇后数*/, chess[MAXN]/*用来记录每一行放的位置*/;

bool place(int t) {
	for(int i=1; i<t; i++)
		if(abs(chess[i]-chess[t])==abs(i-t) || chess[i]==chess[t])
			return 0;
	return 1;
}

void DFS(int i) {
	if(i > Q) { // 因为最终i会达到9，所以终止条件是 i>Q
		ans++;
		for(int j=1; j<=Q; j++)
			printf("%d ",chess[j]);
		printf("\n");
	}
	else {
		for(int j=1; j<=Q; j++) {
			chess[i]=j;
			if(place(i)) //如果可以放，那就到下一层
				DFS(i+1);
		}
	}
}
int main() {
	DFS(1);
	printf("%d",ans);
	return 0;
}
