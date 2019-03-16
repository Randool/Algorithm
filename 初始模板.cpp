#pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC diagnostic error "-std=c++11"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define inf          0x3f3f3f3f
#define go(a,b,c)    for(int a=b;a<=c;a++)
#define gov(a,b)     for(int a=0;a<b.size();a++)
#define rgo(a,b,c)   for(int a=b;a>=c;a--)
#define sf(a)        scanf("%d",&a)
#define sff(a,b)     scanf("%d%d",&a,&b)
#define sfff(a,b,c)  scanf("%d%d%d",&a,&b,&c)
#define eps          1e-9
#define ft           first
#define sd           second
#define prt(a)       printf("%d\n",a)
#define prn(i,n,a)   printf("%d%c",a,i==n?'\n':' ')
#define pb           push_back
#define D(v)         cout<<#v<<"   "<<v<<endl;
#define lowbit(x)    ((x)&(-x))
typedef long long LL;
typedef pair<int,int> pii;
typedef set<int> si;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef double db;
int gcd(int a,int b)
{
    return b ? gcd(b, a%b) : a;
}
const int maxn = 1e3 + 10;
const LL mod = 1e9 + 7;
LL fsp(LL a, LL b)
{
    LL ans=1;
    while(b)
    {
        if(b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}
int read()
{
    int f=1,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f*x;
}

int main()
{
    freopen("in.txt",'r',stdin);
    freopen("out.txt", "w", stdout);


    return 0;
}
