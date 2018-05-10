#include <iostream>
#include <cstdio>
using namespace std;

int subset(int n, int m) {
    if (n < m || m == 0) return 0;
    if (m == 1 || n == m) return 1;
    return subset(n-1, m-1) + m*subset(n-1, m);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "r", stdout);
    int n, k;
    cin >> n >> k;
    cout << subset(n, k) << endl;

    return 0;
}
