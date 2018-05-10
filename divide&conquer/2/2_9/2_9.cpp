#include <cstdio>
#include <iostream>
using namespace std;

void move(int num, char from, char to) {
    printf("%d %c %c\n", num, from, to);
}

void hanoi(int n, char a, char b, char c) {
    if (n > 0) {
        hanoi(n-1, a, c, b);
        move(n, a, b);
        hanoi(n-1, c, b, a);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');

    return 0;
}
