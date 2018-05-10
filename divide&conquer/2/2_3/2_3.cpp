#include <iostream>
#include <cstdio>
using namespace std;

int half_num_set(int n) {
    if (n <= 1) return 1;
    int cnt = 0;
    for (int i = 0; i <= n/2; ++i) {
        cnt += half_num_set(i);
    }
    return cnt;
}

int memory[1000];

int half_num_set_pro(int n) {
    if (n <= 1) return 1;
    if (memory[n]) return memory[n];
    int cnt = 0;
    for (int i = 0; i <= n/2; ++i) {
        cnt += half_num_set_pro(i);
    }
    memory[n] = cnt;
    return cnt;
}

int main() {
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    cout << half_num_set_pro(n) << endl;
    //cout << half_num_set(n) << endl;

    return 0;
}
