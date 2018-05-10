#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
typedef unsigned long long LL;
using namespace std;

LL hanoi[25];

int main()
{
    //每次移动一定是移到中间杆或从中间移出
    //允许最大的盘子放到最上面
    hanoi[0] = 0;
    hanoi[1] = 2;
    for (int i=2; i<=35; ++i)
        hanoi[i] = hanoi[i-1]*3 + 2;

    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d" ,&n);
        printf("%lld\n", hanoi[n-1]+2);
    }

    return 0;
}
