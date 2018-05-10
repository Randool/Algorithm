#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Room {
	int J;
	int F;
	double r;
} room[1005];

bool cmp(Room &a, Room &b) {
	return a.r > b.r;
}

int main() {
	int M,N; //M cat food; N rooms
	while(~scanf("%d%d",&M,&N))
	{
		if(M==-1 || N==-1)
			break;
		for(int i=1; i<=N; i++) {
			scanf("%d%d", &room[i].J, &room[i].F);
			room[i].r = 1.0 * room[i].J / room[i].F;
		}
		if(N>1) sort(room+1,room+1+N,cmp);
		double ans=0, f=(double)M;
		for(int i=1; i<=N; i++) { //这里不能直接用while(f)，因为有可能 f 比所有的价值总和还要大 
			if(f==0) break;
			if(room[i].F <= f) {
				ans += room[i].J;
				f -= room[i].F;
			}
			else if(room[i].F > f) {
				ans += (room[i].J * f) / room[i].F;
				break;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
