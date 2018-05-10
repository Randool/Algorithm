#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Program {
	int begin, end;
} program[100];

bool cmp(const Program &a, const Program &b) {
	if(a.begin==b.begin) return a.end < b.end;
	else return a.begin < b.begin;
}

int main() {
	int N;
	while(cin>>N && N!=0) {
		for(int i=1; i<=N; i++)
			scanf("%d%d",&program[i].begin,&program[i].end);
		sort(program+1,program+1+N,cmp);
		//Ì°ÐÄ£ºÌ°½áÊøÔçµÄ
		int sum = 1, bound = program[1].end;
		for(int i=2; i<=N; i++) {
			if(bound <= program[i].begin) {
				bound = program[i].end;
				sum++;
			} else if(program[i].end < bound)
				bound = program[i].end;
		}
		printf("%d\n",sum);
	}

	return 0;
}
