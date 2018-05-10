#include <cstdio>
using namespace std;

int gcd(int a, int b) {
    return b==0 ? a : gcd(b, a%b);
}

int main()
{
    int N, m, x, y, ans;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &m);
        scanf("%d", &x); --m;
        ans = x;
        while (m--)
        {
            scanf("%d", &x);
            ans = ans / gcd(ans, x) * x;
        }
        printf("%d\n", ans);
    }
    return 0;
}
