#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
typedef unsigned long long LL;
using namespace std;

LL hanoi[25];

int main()
{
    //ÿ���ƶ�һ�����Ƶ��м�˻���м��Ƴ�
    //�����������ӷŵ�������
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
