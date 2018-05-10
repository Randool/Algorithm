#include <iostream>
using namespace std;
int main()
{
	int n,i,j,l,k,b[200][10];
	cout<<"input n:"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)	//输入初始值 
	{
		cin>>b[i][1];
		b[i][2]=1;b[i][3]=0;
	}
	
	for(i=n-1;i>=1;i--)	//求最长不下降序列 
	{
		l=0;k=0;
		for(j=i+1; j<=n; j++)
			if((b[j][1]>b[i][1]) && (b[j][2]>l))
			{
				l = b[j][2]; k = j;
			}
		if(l>0)
		{
			b[i][2] = l+1;
			b[i][3] = k;
		}
	}
	k = 1;
	for(j=1; j<=n; j++)			//找出最长不下降序列
		if(b[j][2] > b[k][2])
			k = j;
	cout<<"max="<<b[k][2]<<endl; 	//输出结果 
	while(k != 0)				//最长不下降序列长度为b[k][2]序列
	{
		cout << " " << b[k][1];
		k = b[k][3];
	}
	
	return 0;
 } 
