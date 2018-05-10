#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int Ends[10005];

struct Time {
	int begin,end;
} time[10005];

bool cmp(const Time &a, const Time &b) {
	if(a.begin==b.begin) return a.end < b.end;
	else return a.begin < b.begin;
}

int main() {
	int n, ans/*表示有几个结束时间段,即几间教室*/;
	while(cin>>n) {
		ans = 0;
		for(int i=1; i<=n; i++)
			scanf("%d%d", &time[i].begin, &time[i].end);
		sort(time+1, time+1+n, cmp);
		Ends[++ans] = time[1].end;
		int i, j;
		for(i=2; i<=n; i++) {
			bool b = 0; // 表示没找到
			for(j=1; j<=ans; j++) {
				if(time[i].begin >= Ends[j]) { //表示找到了一间教室可以借用
					Ends[j] = time[i].end;
					b=1; // 表示找到
					break;
				}
			}
			if(b==0) //找不到教室，需要再加一个
				Ends[++ans] = time[i].end;
		}
		printf("%d\n",ans);
	}
	return 0;
}
