#include <cstdio>
#include <algorithm>
using namespace std;
int A[100];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&A[i]);
	sort(A,A+n);
	do{
		for(int i=0; i<n; i++)
			printf("%d ", A[i]);
		printf("\n");
	} while(next_permutation(A,A+n));
	return 0;
}
