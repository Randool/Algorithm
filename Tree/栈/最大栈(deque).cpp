#include <deque>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;

LL n, A, B, C, x, a, b, mod;
deque<LL> dq, Max;
typedef deque<LL>::iterator iter;
// 5 1 1 1 2 2 2 5
int main()
{
    LL MOD = 1000000007;
    LL act, num, times = 0, result = 0;
    while (~scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &n, &A, &B, &C, &x, &a, &b, &mod))
    {
        ++times;
        x = (x*a+b) % mod;
        if ( dq.size() <= 1 || x % (A+B+C) < A) act = 0, num = x;
        else if (A <= x%(A+B+C)) act = 1, num = times;
        else act = 2;

        cout << act << " " << num << endl;

        if (act == 0) //push front
        {
            dq.push_front(num);
            if (Max.empty())
                Max.push_front(num);
            else if (num > Max.front())
                Max.push_front(num);
            else
                Max.push_front(Max.front());
        }
        else if (act == 1) //push back
        {
            dq.push_back(num);
            iter i = Max.end()-1;
            while ((*i) < num) {
                (*i) = num;
                --i;
            }
            Max.push_back(num);
        }
        else // pop
        {
            Max.pop_front();
        }
        result = (Max.front() + result) % MOD;
    }
    printf("%lld\n", result);

    return 0;
}
