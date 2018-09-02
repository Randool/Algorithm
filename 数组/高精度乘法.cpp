#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 10000
#define BASE 100000
using namespace std;

int num[MAXN];

int main()
{
    // ÿһ�񱣴��������һλ���Ƕ�λ
    int n;
    while (~scanf("%d", &n))
    {
        memset(num, 0, sizeof(num));
        num[MAXN-1] = 1;
        for (int i = 1; i<=n; ++i)
        {
            int carry = 0;
            for (int k = MAXN-1; k>=0; --k) //�����һλ��ʼ���, ������ǰ��ÿһλ���
            {
                carry += i * num[k];
                num[k] = carry % BASE;
                carry /= BASE; //��λ
            }
        }
        int index;
        for (index = 0; index<MAXN && num[index]==0; ++index); // Ѱ�ҵ�һ������0����

        printf("%d", num[index++]); //��һλ���ܲ�����λ���͵����

        for (index; index < MAXN; ++index)
            printf("%05d", num[index]); //�����м��ֵҲ����û����λ������߼�0������5λ

        printf("\n");
    }
    return 0;
}
