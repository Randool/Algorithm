#include <cstdio>
#include <cstring>
#include <iostream>
typedef unsigned long long LL;
using namespace std;

LL hanoi[40];

int main()
{
    //ÿ���ƶ�һ�����Ƶ��м�˻���м��Ƴ�
    int n;
    hanoi[0] = 0;
    hanoi[1] = 2;
    for (int i=2; i<=35; ++i)
        hanoi[i] = hanoi[i-1] * 3 + 2;

    while (~scanf("%d", &n))
        cout << hanoi[n] << endl;

	return 0;
}

