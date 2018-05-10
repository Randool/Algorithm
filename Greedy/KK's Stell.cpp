#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

LL f[10000];

void Init()
{
	f[1] = 1;
	f[2] = 2;
	for (int i=3; i<1000; i++)
		f[i] = f[i-2] + f[i-1];
}

int main()
{
	int t;
	LL m;
	scanf("%d", &t);
	Init();
	while(t--)
	{
		cin >> m;
		LL sum = 0;
		for (int i=1; ;i++)
		{
			sum += f[i];
			if(sum == m)
			{
				printf("%d\n", i);
				break;
			}
			else if(sum > m)
			{
				printf("%d\n", i-1);
				break;
			}
		}
	}
	return 0;
}
