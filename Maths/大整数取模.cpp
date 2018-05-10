/*大整数取模*/
/*输入正整数 n和 m，输出 n mod m，n<=10^100, m<=10^9 */ 
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int m;
	char num[105];
	while(scanf("%s%d", &num, &m)==2) {
		int ans = 0;
		int len = strlen(num);
		for(int i=0; i<len; i++)
			ans = (int)(((long long)ans*10 + num[i] - '0') % m);
		//printf("%d\n", ans); 
		printf("%m\n");
		printf("%s mod %d = %d\n\n", num,m, ans);
		memset(num, 0, sizeof(num));
	}
	return 0;
}
