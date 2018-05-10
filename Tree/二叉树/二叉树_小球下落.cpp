#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20;
int s[1<<maxn];
int main() {
	int D, I;
	while(scanf("%d%d", &D, &I) == 2) {
		memset(s, 0, sizeof(s));//开关
		int k, n = (1<<D)-1;	//n是最大节点的编号
		for(int i = 0; i < I; i++) {
			k = 1;
			for(;;) {
				s[k] = !s[k];	//改变开关状态 
				k = (s[k] ? k*2 : k*2+1);	//根据开关状态选择方向 
				//printf("%d\n", k);
				if(k > n) break;
			}
		}
		printf("%d\n", k/2);
	}
	return 0;
}
