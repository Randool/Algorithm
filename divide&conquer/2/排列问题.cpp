#include <cstdio>
#include <iostream>
using namespace std;

void Perm(int arr[], int p, int q) {
    if (p == q) {
        for (int i = 0; i <= q; ++i)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else {
        for (int i = p; i <= q; ++i) {
            swap(arr[i], arr[p]);
            Perm(arr, p+1, q);
            swap(arr[i], arr[p]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    Perm(arr, 0, 3);
    return 0;
}
