#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define MAXN 100010
using namespace std;
#define lowbit(x)	x&(-x)
#define sf(n)	    scanf("%d",&n)
#define sff(a,b)	scanf("%d%d",&a,&b)
#define sfff(a,b,c)	scanf("%d%d%d",&a,&b,&c)

int N,s,e;
int c[MAXN];
int index, start, end;

struct Cows{
    int index;
    int s,e;
} cow[MAXN];

bool cmp(const struct Cows a, const struct Cows b) {
	if(a.s!=b.s) return a.s < b.s;
	else return a.e < b.e;
}

void update(int x, int t) {
    while(x <= MAXN) {
        c[x] += t;
        x += lowbit(x);
    }
}

int getSum(int x) {
	int s = 0;
    while(x) {
        s += c[x];
        x -= lowbit(x);
    }
	return s;
}

int main()
{
    freopen("in.txt", "r", stdin);
    
	while(~sf(N),N)
    {
    	memset(c,0,sizeof(c));
        for(int i=1; i<=N; i++) {
            sff(cow[i].s, cow[i].e);
            cow[i].s ++;
			cow[i].e ++; 
            cow[i].index = i;
        }

        sort(cow+1,cow+1+N,cmp);
        
        update(cow[1].s, 1);
        
        for(int i=2; i<=N; i++) {
        	index = cow[i].index;
        	start = cow[i].s;
        	end = cow[i].e;
        	if(end==cow[i-1].e && start==cow[i-1].s)
        		c[index] = c[cow[i-1].index];
        	else
        		c[index] = getSum(cow[i].s);
        	update(cow[i].s, 1);
        }
        
        for(int i=1; i<=N; i++) {
        	printf("%d", c[i]);
        	if(i!=N) printf(" ");
			else printf("\n");
		}
    }
	return 0;
}
