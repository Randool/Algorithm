#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int b[200][200], n, N, i, j, max;
	cin>>N;
	while(N--)
	{
		cin>>n;
		memset(b,0,sizeof(b));
	//注意从 i=1 开始输入！考虑边际! 
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				cin>>b[i][j];
	//选择路径，保留路径最大值 
	//向下叠加，将最大结果保留在最底层 
		for(i=2;i<=n;i++)
			for(j=1;j<=i;j++)
			{
				if(b[i-1][j-1]>b[i-1][j])
					b[i][j]=b[i][j]+b[i-1][j-1];
				else
					b[i][j]=b[i][j]+b[i-1][j];
			}
		max=0;
		for(j=1;j<=n;j++)
			if(b[n][j]>max)
				max=b[n][j];
	
		cout<<"Max="<<max<<endl;	//输出数塔的最大值 
	}
	return 0;
}
