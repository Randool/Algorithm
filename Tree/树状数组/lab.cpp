#include <bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a))
#define N 100005
#define EXP 1e-8
#define lowbit(x) (x&-x)
using namespace std;

vector<vector<int> > a(N);
int n,m,lef[N],rig[N],c[N],tot,s[N];

int sum(int x) {
	int ret = 0;
	while(x>0) {
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}

void add(int x,int d) {
	while(x<=n) {
		c[x]+=d;
		x+=lowbit(x);
	}
}

void dfs(int x) {
	lef[x] = tot;
	for(int i = 0; i<a[x].size(); i++) {
		tot++;
		dfs(a[x][i]);
	}
	rig[x] = tot;
}

int main() {
	// freopen("in.txt", "r", stdin);
	int i,j,k,x,y;
	char op[5];
	while(~scanf("%d",&n)) {
		MEM(lef,0);
		MEM(rig,0);
		MEM(c,0);
		for(i=0; i<N; i++)
			a[i].clear();

		for(i = 1; i<n; i++) {
			scanf("%d%d",&x,&y);
			a[x].push_back(y);
		}

		tot = 1;
		dfs(1);
		cout << "tot = " << tot << endl;

		for(i = 1; i<=n; i++) {
			s[i] = 1;
			add(i,1);
		}

		scanf("%d",&m);
		while(m--) {
			scanf("%s%d",op,&x);
			if(op[0]=='Q') {
				printf("%d\n", sum(rig[x])-sum(lef[x]-1));
			} else {
				if(s[x])
					add(lef[x],-1);
				else
					add(lef[x],1);
				s[x]=!s[x];
			}
		}
	}

	return 0;
}
