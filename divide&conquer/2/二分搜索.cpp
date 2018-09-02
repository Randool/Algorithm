#include <cstdio>
#include <functional>
using namespace std;

int BinarySearch(int arr[], int target, int n) {
    int p = 0, q = n-1, mid;
    while (p <= q) {
        mid = (p + q) >> 1;
        //printf("%d\n", mid);
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target) p = mid + 1;
        else q = mid - 1;
    }
    return -1;
}

int main() {
    int tar, arr[] = {1, 2, 3, 4, 5, 9, 10, 15, 16};

    while (~scanf("%d", &tar))
        printf("%d\n", BinarySearch(arr, tar, 9));

    return 0;
}
