#include <cstdio>
#include <queue>
using namespace std;
priority_queue< int, vector<int>, greater<int> > q;
int main() {
	int N, t, sum;
	long long ans;
	while(~scanf("%d",&N)) {
		while(!q.empty()) q.pop();
		for(int i=0; i<N; i++) {
			scanf("%d",&t);
			q.push(t);
		}
		ans = 0;
		while(q.size() != 1) {
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			sum = a+b;
			ans += sum;
			q.push(sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
9
1 3 3 4 6 5 9 10 15
163*/
