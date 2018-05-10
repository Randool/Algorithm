#include <iostream>
#include <algorithm>
using namespace std;

struct Act {
	int begin, end;
} act[10005];

/*贪心思想： 
贪结束时间最早的*/

bool cmp(const Act &a, const Act &b) {
	if(a.end==b.end) return a.begin > b.begin;
	else return a.end < b.end;
}

int main() {
	int N, ans, end;
	while(cin>>N) {
		for(int i=1; i<=N; i++)
			cin>>act[i].begin>>act[i].end;
		sort(act+1,act+1+N,cmp);
		ans=1;
		end=act[1].end;
		for(int i=2; i<=N; i++) {
			if(act[i].begin >= end) {
				ans++;
				end=act[i].end;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
