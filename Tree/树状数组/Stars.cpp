#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Star {
	int x, y;
}	s[15002];
int N;
int level[32005];
int Count[32005];

bool cmp(const Star a, const Star b) {
	if(a.x < b.x) return 1;
	else if(a.x > b.x) return 0;
	else return a.y < b.y;
}

int lowbit(int x) {
	return x & (-x);
}

void update(int x) {
	while(x <= 32005) {
		Count[x] ++;
		x += lowbit(x);
	}
}

int getSum(int x) {
	int ans = 0;
	while(x > 0) {
		ans += Count[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	while(~scanf("%d", &N) && N) {
		for(int i=0; i<N; i++)
			scanf("%d%d", &s[i].x, &s[i].y);
		sort(s, s+N, cmp);
		memset(Count,0,sizeof(Count));
		memset(level,0,sizeof(level));
		int tmp;
		for(int i=0; i<N; i++) {
			tmp = getSum(s[i].y+1);
			level[tmp] ++;
			update(s[i].y+1);
		}

		for(int i=0; i<N; i++)
			printf("%d\n", level[i]);
	}

	return 0;
}
