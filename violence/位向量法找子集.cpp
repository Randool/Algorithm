#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int num[100];
bool choose[100];
void print_sub(int n, int cur) {
	if(cur==n){
		for(int i=0; i<n; i++)
			if(choose[i]==1)
				printf("%d ",num[i]);
		printf("\n");
		return; 
	}
	choose[cur]=0; //ฒปัก
	print_sub(n,cur+1);
	choose[cur]=1; //ัก
	print_sub(n,cur+1); 
}

int main () {
	int n;
	printf("Enter the n:\n");
	scanf("%d",&n);
	printf("Enter the numbers:\n");
	for(int i=0; i<n; i++)
		scanf("%d",&num[i]);
	sort(num,num+n);
	memset(choose,0,sizeof(choose));
	print_sub(n,0);
 	return 0;
 }
