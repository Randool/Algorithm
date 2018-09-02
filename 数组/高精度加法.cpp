#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	char a1[400], b1[400];
	int a[400], b[400], c[400], alen, blen, clen, i, x, temp;
	//初始化数组 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	//输入两串字符 ，空格结束输出。 
	gets(a1);
	gets(b1);
	//获得长度 
	alen = strlen(a1);
	blen = strlen(b1);
	//char-->int
	for(i = 0; i < alen; i++)	a[alen-i] = a1[i]-48;
	for(i = 0; i < blen; i++)	b[blen-i] = b1[i]-48;
	//转存c 
	x = 1; temp = 0;
	while(x <= alen || x <= blen){
		c[x] = a[x] + b[x] + temp;
		temp = c[x] / 10;
		c[x] %= 10;	
		x++;
	}
	c[x] = temp;
	//输出 
	if(c[x] == 0)	x--;
	for(i=x; i>=1; i--)
		cout<<c[i];	
	
	return 0;
}
