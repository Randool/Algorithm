#include <algorithm>
#include <ctime>
#include <cstdio>
using namespace std;

template <typename E>
inline int partition(E *A, int l, int r) {
    int pivotV = A[r];
    int p = l-1, q = r+1;
    while (p < q) {
        while (A[++p] < pivotV);
        while (pivotV < A[--q]);
        swap(A[p], A[q]);
    }
    swap(A[p], A[r]);
    return p;
}

/**
  * @@ return the index of the partition
  */
template <typename E>
int random_partition(E *A, int l, int r) {
    int pivot = rand() % (r-l+1) + l;
    swap(A[pivot], A[r]);
    return partition(A, l, r);
}

/**
  * @@ k: the k-th small number in the array.
  */
template <typename E>
E select(E *A, int l, int r, int k) {
    if (l == r) return A[l];
    int q = random_partition(A, l, r);
    int p = q - l + 1;

    if (k == p)
        return A[p];
    else if (p < k)
        select(A, l, q-1, k);
    else
        select(A, q+1, r, k-p);
}

int main() {
    srand((unsigned)time(0));
    int A[20];
    for (int i = 0; i < 20; ++i)
        A[i] = rand() % 100;

    int mid = select<int> (A, 0, 20, 10);
    printf("%d\n", mid);

    sort(A, A+20);
    for (int i = 0; i < 20; ++i)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
