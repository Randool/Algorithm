#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

/*Sort函数有三个参数：
（1）第一个是要排序的数组的起始地址。
（2）第二个是结束的地址（最后一位要排序的地址）
（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。

Sort函数使用模板:
	Sort(start,end,排序方法)

同时，sort是原地址修改 
*/ 
	bool complare(int a , int b)
	{
		return a > b ;	// " > " 按照这个方向排列 
	}

int main()
{
	int a[10] = {9,6,3,8,5,2,7,4,1,0} ;
	for(int i = 0; i < 10; i++)
		cout<<a[i]<< " " ;
	cout << endl;

//--------------------//从小到大 
	sort(a,a+10) ;
	for(int i = 0; i < 10; i++)
		cout << a[i] << " " ;
	cout<<endl;

//--------------------//从大到小 	
	sort(a , a + 10 , complare); //在这里就不需要对complare函数传入参数了，这是规则
	for(int i = 0; i < 10; i++)
		cout << a[i] << " " ;
	cout << endl;

//--------------------//
	//c++标准库提供方便的函数 Sortt作为第三个参数
	//还可以用这样的语句告诉程序你所采用的排序原则

//--------------------//less<数据类型>()	从小到大排序
	sort( a , a+10 , less<int>() );
	for( int i = 0 ; i < 10 ; i++ )
		cout << a[i] << " " ;
	cout << endl;

//--------------------//greater<数据类型>()	从大到小排序
	sort( a , a+10 , greater<int>() );
	for( int i = 0; i < 10; i++ )
		cout << a[i] << " " ;
	cout << endl;

//--------------------//sort还可以对字符进行排列
	char b[15] = "asdAfghjHkZlFk";		//字符数组末位是 \0 ，需要一个空位，因此 a[15] 
	
	for( int i = 0 ; i < 15 ; i++ )
		cout << b[i] << " " ;
	cout << endl;
	
	sort( b , b+15 , less<char>() );
	for( int i = 0 ; i < 15 ; i++ )
		cout << b[i]<< " " ;
	cout << endl;
	
	sort( b , b + 15 , greater<char>() ); 
	for( int i = 0 ; i < 15 ; i++ )
		cout << b[i] << " " ;
	cout << endl; 
	
return 0 ;
}


