#include <iostream>
using namespace std;
int main() {
	int n, u, d, time, i;
	while(cin>>n>>u>>d && n!=0) {
		if(n<=u) time = 1;
		else {
			for(i=0;; i++)
				if(n<=(u-d)*i+u)
					break;
			time = i*2+1;
		}
		cout << time << endl;
	}
	return 0;
}
