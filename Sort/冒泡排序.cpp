#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;

int main()
{
	int arr[]={98,93,87,99,95};//5¸öÔªËØ 
	int i,j;
	for(i=4;i>=0;i--)
		for(j=0;j<=i;j++)
			if(arr[j]>arr[j+1])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	for(i=0;i<=4;i++)
		cout<<arr[i]<<" ";
		
	return 0;
} 

