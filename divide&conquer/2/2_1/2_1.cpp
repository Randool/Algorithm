#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

typedef map<int,int> Mii;
Mii mii;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        mii[t] += 1;
    }
    int result_x, result_cnt = 0;
    for (Mii::iterator iter = mii.begin(); iter != mii.end(); ++iter) {
        if (iter->second > result_cnt) {
            result_x = iter->first;
            result_cnt = iter->second;
        }
    }
    printf("%d\n%d", result_x, result_cnt);

    return 0;
}
