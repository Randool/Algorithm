#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#define MAXN 1010
using namespace std;
#define sf(n)	scanf("%d",&n)
#define sff(a,b)	scanf("%d%d",&a,&b)
#define sfff(a,b,c)	scanf("%d%d%d",&a,&b,&c)

int M, N; // <=1000
int K, T;
long long cnt;
int map[MAXN][MAXN];

int lowbit(int x) {
	return x & (-x);
}
void update(int x, int y, int t) {
	while(x < MAXN) {
		int yy = y;
		while(yy < MAXN) {
			map[x][yy] += t;
			yy += lowbit(yy);
		}
		x += lowbit(x);
	}
}
int getSum(int x, int y) {
	int cnt = 0;
	while(x) {
		int yy = y;
		while(yy) {
			cnt += map[x][yy];
			yy -= lowbit(yy);
		}
		x -= lowbit(x);
	}
	return cnt;
}

void Show(int N) {
	for(int i=1; i<=M; i++)
	{
		for(int j=1; j<=N; j++)
			cout << setw(3) << map[i][j] << " ";
		printf("\n");
	}
	printf("\n");
}
void Show_map(){
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
            cout << getSum(i,j) << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int Cases = 0;
	sf(T);
	while(T--) {
		memset(map,0,sizeof(map));
		int a,b,tmp;
		cnt = 0;
		sfff(N,M,K);
		for(int i=1; i<=K; i++) {
			scanf("%d%d", &a, &b);
			update(a+1,1,1);
			update(a+1,b,-1);
			update(1,b+1,1);
			update(a,b+1,-1);
			tmp = getSum(a,b);
			cnt += tmp;
			//Show_map();
		}
		printf("Test case %d: %lld\n",++Cases,cnt);
	}
	return 0;
}
