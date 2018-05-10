#include <cstdio>
#include <cstring>
#include <iostream>
typedef unsigned long long LL;
using namespace std;

LL hanoi[40];

int main()
{
    //每次移动一定是移到中间杆或从中间移出
    int n;
    hanoi[0] = 0;
    hanoi[1] = 2;
    for (int i=2; i<=35; ++i)
        hanoi[i] = hanoi[i-1] * 3 + 2;

    while (~scanf("%d", &n))
        cout << hanoi[n] << endl;

	return 0;
}

