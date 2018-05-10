#include <cstdio>
#include <iostream>
using namespace std;

void Permutation(int *list, int cur, const int len) {
    if (cur == len-1) {
        for (int i = 0; i < len; ++i) printf("%d ", list[i]);
        printf("\n");
        return;
    }
    for (int i = cur; i < len; ++i) {
        swap(list[cur], list[i]);
        Permutation(list, cur+1, len);
        swap(list[cur], list[i]);
    }
}

int main() {
    int a[3];
    for (int i = 1; i <= 3; ++i) a[i-1] =  i;
    Permutation(a, 0, 3);
    return 0;
}
