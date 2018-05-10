#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define MAXN 1002
typedef unsigned long long ull;
using namespace std;

ull F[MAXN*MAXN];

//¼ÆËã f(a^b) mod n
int main() {
	ull a, b, n;
	while(cin >> a >> b >> n)
	{
		ull flag;
		F[0] = F[1] = 1;
		for(ull i = 2; i<=n*n; i++)
		{
			F[i] = (F[i-2] % n + F[i-1] % n) % n;
			if(F[i] == F[0] && F[i-1] == F[1])
			{
				flag = i-1; //ÖÜÆÚ 
				break;
			}
		}
		if(a==0 && n==1) printf("0\n");
		else {
			int t = flag;
			ull result = 1;
			while(b)
			{
				if(b%2)
					result = (a*result) % t;
				a = (a*a) % t;
				b /= 2;
			}
			cout << F[result] << endl;
		}
	}
	
	return 0;
}
