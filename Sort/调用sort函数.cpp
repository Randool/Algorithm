//n个大理石，写上非负数
//先把各大理石从大到小排列，然后回答q个问题
//是否有大理石上写着x，如果是，回答哪个位子上写着x 
#include<iostream>
#include<cstdio>
#include<algorithm>		//调用sort函数需要头文件algorithm（算法） 
using namespace std;
const int maxn = 10000;

int main()
{
	int n, q, x, a[maxn], kase=0;
	while(scanf("%d%d", &n, &q) == 2 && n)	//&& n 是为了防止 n 为 0 
	{
		printf("CASE# %d:\n", ++kase);
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &a[i]);
		
		sort(a, a+n);		//排序 
		
		while(q--)
		{
			scanf("%d", &x);
			int p = lower_bound(a,a+n,x) - a;	//lower_bound 的作用是查找“大于或等于 x 的第一个位置” 
			
			if(a[p] == x)
				printf("%d found at %d\n", x, p+1);
			else
				printf("%d not found\n", x);
		}
	}
	return 0;
}
