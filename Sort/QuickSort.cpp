#include <iostream>
using namespace std;

template <class Type>
int Partition(Type a[], int p, int q) {
    int i = p;
    int j = q + 1;
    Type x = a[p];
    while (true)
    {
        while (a[++i] < x && i<q);
        while (a[--j] > x);
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}

template <class Type>
void qsort(Type a[], int p, int q) {
	if (p < q)
    {
        int mid = Partition(a, p, q);
        qsort(a, p, mid-1);
        qsort(a, mid+1, q);
    }
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n+5];

	for (int i=0; i<n; ++i)
        cin >> a[i];

    qsort(a, 0, n-1);

    for (int i=0; i<n; ++i)
        cout << a[i] << " ";
	return 0;
}
