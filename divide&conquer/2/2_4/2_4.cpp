#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

// 0 < n < 201
//   24 50
int mem[205];
int single_half_num_set(int n) {
    if (mem[n]) return mem[n];
    int cnt = 1;
    for (int i = 1; i <= n/2; ++i) {
        cnt += single_half_num_set(i);
        if ( (i>10) && (2 * (i/10) <= i % 10) )
            cnt -= mem[i/10];
    }
    mem[n] = cnt;
    return cnt;
}

int main() {
    int n, total = 0;
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    cout << single_half_num_set(n) << endl;

    return 0;
}
