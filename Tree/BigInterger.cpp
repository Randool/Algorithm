#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#define MAXN 1005
using namespace std;

struct BigInterger
{
    vector<int> s;
    static const int BASE = 100000000;
    static const int WIDTH = 8;

    BigInterger(long long num = 0) { *this = num; }

    BigInterger operator = (long long num)
    {
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        } while(num > 0);
        return *this;
    }

    BigInterger operator = (const string& str)
    {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i=0; i<len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    BigInterger operator + (const BigInterger& b) const {
        BigInterger c;
        c.s.clear();
        for (int i=0, g=0; ;i++) {
            if(g == 0 && i >= s.size() && i >= b.s.size())
                break;
            int x = g;
            if (i < s.size())
                x += s[i];
            if (i < b.s.size())
                x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
};

BigInterger num[MAXN];

int main()
{
    int n;
    scanf("%d", &n);

    num[1] = num[2] = 1;
    for (int i=3; i<=1005; i++)
        num[i] = num[i-2] + num[i-1];
    int N;

    while(n--)
    {
        scanf("%d", &N);
        for (int i=num[N].s.size()-1; i>=0; i--)
            printf("%d", num[N].s[i]);
        printf("\n");
    }
}
