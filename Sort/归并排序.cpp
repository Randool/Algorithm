#include <iostream>
using namespace std;
void merge_sort(int *A, int x, int y, int *T) {
	if(y > x+1) {
		int m = x + (y-x)/2;	//划分中间值 
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);	//递归求解, 把左半部分排序 
		merge_sort(A, m, y, T);	//递归求解，把右半部份排序 
		while(p < m || q < y) {
			if(q >= y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];	//从左半数组取一个小数字 
			else
				T[i++] = A[q++];	//从右半数组取一个小数字 
		}
		for(i = x; i < y; i++)
			A[i] = T[i];	//从辅助数组复制回原数组 
	}
}
int main()
{
	int N, i, A[100], T[100];
	cin >> N;
	for(i=1; i<=N; i++)
		cin >> A[i];
	merge_sort(A, 1, N, T);
	for(i=1; i<=N; i++)
		cout << A[i] << " ";
	return 0;
}
