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
	//ע��� i=1 ��ʼ���룡���Ǳ߼�! 
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				cin>>b[i][j];
	//ѡ��·��������·�����ֵ 
	//���µ��ӣ����������������ײ� 
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
	
		cout<<"Max="<<max<<endl;	//������������ֵ 
	}
	return 0;
}
