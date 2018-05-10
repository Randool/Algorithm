#include <iostream>
#include <cstring>
using namespace std;
int a[100000][3];
int main() {
	int n, i, j, k, l;
	while(cin >> n) {
		for(i=1; i<=n; i++) {	//输入数据、初始化
			cin >> a[i][1];
			a[i][2] = 1;
		}

		//a[1][2]=1;
		for(i=2; i<=n; i++) {	//标记
			l = 0;
			for(j=1; j<=i-1; j++) {
				if((a[i][1] > a[j][1])  &&  (a[j][2] > l)) {
					l = a[j][2];
					a[i][2] = a[j][2] + 1;
				}
			}
		}
		k=1;
		for(i=1; i<=n; i++)
			if(a[i][2]>k)
				k=a[i][2];
		cout<<k<<endl;
	}
	return 0;
}
//7
//1 7 3 5 9 4 8
//Sample Output
//4
