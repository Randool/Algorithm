#include <stdio.h>
#include <cstring>
using namespace std;
int main() {
	int D, I;
	while(scanf("%d%d", &D, &I) == 2) {
		int k = 1;
		for(int i=1; i<=D-1; i++)
			if(I%2==0) 
				{ k = k*2+1; I/=2; }
			else
				{ k = k*2; I = (I+1)/2; }
		printf("%d\n", k);
	}

	return 0;
}
