/*按照释放的空间从大到小排序，因为释放的空间越大后面的任务能新开辟的空间也就越小*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Task{
	int run, back;
} a[100005];

bool cmp(const Task &a, const Task &b) {
	return (a.run-a.back) > (b.run-b.back);
}

int main() {
	int N;
	while(~scanf("%d",&N)) {
		for(int i=1; i<=N; i++)
			scanf("%d%d",&a[i].run,&a[i].back);		
		sort(a+1, a+1+N, cmp);
		int memory = a[1].run;
		for(int i=2; i<=N; i++) {
			memory += (a[i].run - (a[i-1].run-a[i-1].back));
		}
		printf("%d\n",memory);
	}
	
	return 0;
}
/*
3
19 6
14 1
10 7
*/
