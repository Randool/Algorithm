#include <iostream>
using namespace std;
int main()
{
	int n, m, i, j, k, step = 0;
	cin >> n >> m >> k;
	int a[100];
	for(i = 1; i < n; i++)  
		a[i] = i + 1;		//生成链表，前一位指向后一位 
	a[n] = 1;  				//最后一位指向队列第一位 
	a[0] = m;  				//初始值
	for(i = 1;i < n; i++)			// n - 1次后会决出胜负 
	{
		for(j = 1; j < k; j++)		//数 k - 1次 
			step = a[step];
		//第 k 次，输出step指向的下一位，该人出列，step指向下下位 
		cout << i << ": " << a[step] << "\n";
		a[step] = a[a[step]];
	}
	cout << "winner: " << a[step];
	return 0;
}
