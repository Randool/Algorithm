/*树状数组可以记录逆序数
数据量较大，排序的计数器用 long long */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 500005

int N, t;
int d[MAXN];
int tmp[MAXN];
pair<int, int> pii[MAXN];

int lowbit(int x) { return x & (-x); }

void update(int x, int t) {
	while(x < N+5) {
		d[x] += t;
		x += lowbit(x);
	}
}

int getSum(int x) {
	int s = 0;
	while(x) {
		s += d[x];
		x -= lowbit(x);
	}
	return s;
}

int main() {
	freopen("in.txt", "r", stdin);

	while(~scanf("%d", &N) && N) {
		memset(d,0,sizeof(d));
		memset(pii,0,sizeof(pii));

		long long cnt = 0;

		for(int i=1; i<=N; i++) {
			scanf("%d", &pii[i].first);
			pii[i].second = i;
		}

		sort(pii+1, pii+N+1);

		for(int i=1; i<=N; i++)
			tmp[pii[i].second] = i;

		for(int i=1; i<=N; i++) {
			update(tmp[i], 1);
//			for(int j=1; j<=N; j++)
//				printf("%d ", d[j]);
//			printf("\n");
			cnt += i - getSum(tmp[i]);
		}

		cout << cnt << endl;
	}

	return 0;
}
