#include <cstdio>
#include <cstring>
#include <iostream>
#define mod 10001
using namespace std;
//xi = (a * xi-1 + b) mod 10001

int x[20005];

int main() {
	int n;
	while(cin >> n)
	{
		for(int i=1; i<=n; i++)
			cin >> x[2*i-1];
		for(int a=0; a<=10000; a++)
		{
			int x2 = x[1] * a % mod;
			int b  = x2 * a 
		}
	}
	
	return 0;
}

//https://vjudge.net/problem/29809;jsessionid=58271D60BFF951D6054752001E3650DB
