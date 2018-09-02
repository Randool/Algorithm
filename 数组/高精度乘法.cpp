#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 10000
#define BASE 100000
using namespace std;

int num[MAXN];

int main()
{
    // 每一格保存的数不是一位而是多位
    int n;
    while (~scanf("%d", &n))
    {
        memset(num, 0, sizeof(num));
        num[MAXN-1] = 1;
        for (int i = 1; i<=n; ++i)
        {
            int carry = 0;
            for (int k = MAXN-1; k>=0; --k) //从最后一位开始相乘, 依次向前与每一位相乘
            {
                carry += i * num[k];
                num[k] = carry % BASE;
                carry /= BASE; //进位
            }
        }
        int index;
        for (index = 0; index<MAXN && num[index]==0; ++index); // 寻找第一个不是0的数

        printf("%d", num[index++]); //第一位可能不足五位，就地输出

        for (index; index < MAXN; ++index)
            printf("%05d", num[index]); //处在中间的值也可能没有五位，往左边加0，凑足5位

        printf("\n");
    }
    return 0;
}
